package maple2c_work;

use Regexp::Common;
use List::Util 'all';

use Exporter;
@ISA = qw(Exporter);
@EXPORT = qw(
%config
maple2c_create_derivatives 
maple2c_run_maple
maple2c_replace
maple2c_construct_arguments
maple2c_print_header
maple2c_run
);

our %config = ();
1; # return true value

sub maple2c_create_derivatives
{
  my @variables   = @{$_[0]};
  my @derivatives = @{$_[1]};
  my $func        = $_[2];
  my $spin        = $_[3];
  
  my $out_derivatives = "";
  my @out_cgeneration = ();

  my $realvars = join(", ", @variables);

  foreach $der_order (@derivatives){
    foreach $der (@{$der_order}){
      my ($order, $name) = @{$der};

      # First we find the function to differentiate and wrt what
      my @to_derive = @{$order};

      # is there something to do?
      last if(all { $_ == 0 } @to_derive);

      my $i_to_derive = 0;
      for(; $i_to_derive <= $#to_derive; $i_to_derive++){
        if($to_derive[$i_to_derive] != 0){
          $to_derive[$i_to_derive]--;
          last;
        }
      }
      my $f_to_derive = "$func";
      $f_to_derive = "d".$func."d".join("", @to_derive) if(! all { $_ == 0 } @to_derive);

      # we build the expression of the derivative
      my $varname  = "d".$func."d".join("", @{$order});
      my $vars     = "v".join(", v", 0..$#{$order});
      my $derorder = join(", ", @{$order});

      $out_derivatives .= "$varname := ($vars) ->  diff($f_to_derive($vars), v".
          $i_to_derive."):\n\n";
      
      push @out_cgeneration, "$name = $varname($realvars)";

      last if $spin ne "pol";
    }
  }
  return ($out_derivatives, @out_cgeneration);
}

sub maple2c_run_maple {
  my ($type, $code, $derivatives, $start_order) = @_;

  # save maple file
  # print "Generating: /tmp/$$.mpl\n";
  open($mfile, ">/tmp/$$.mpl");
  printf $mfile "%s", "
Polarization := \"$type\":
Digits := 20:             (* constants will have 20 digits *)
interface(warnlevel=0):   (* supress all warnings          *)
with(CodeGeneration):

\$include <$config{'functional'}.mpl>:

$code
";
  close($mfile);

  # run maple
  my $c_code = `maple -I$config{"srcdir"}/maple -q -u /tmp/$$.mpl`;
  #unlink "/tmp/$$.mpl";

  # find all variables defined in the c code
  my $new_c_code = "";
  my $variables  = "";
  my $n_var = 0;

  my @test_1 = ("zk", "vrho", "v2rho2", "v3rho3", "v4rho4", "v5rho5");
  my @test_2 = ("EXC", "VXC", "FXC", "KXC", "LXC", "MXC");  

  for (split /^/, $c_code) {
    my $found = 0;
    foreach my $der_order (@{$derivatives}){
      my $total_order = ${$der_order}[-1][0][1] + $start_order;
      # search for a vrho = statement
      foreach my $der (@{$der_order}){
        if($_ =~ /^\s*?${$der}[1]\s*=/){
          ${$der}[1] =~ /_([0-9]+)_/;
          if (($type eq "pol") || ($1 == 0)) {
            my $test = $test_1[$total_order]." != NULL";
            $test .= " && (p->info->flags & XC_FLAGS_HAVE_".$test_2[$total_order].")";
            $new_c_code .= "  if($test)\n";
            $new_c_code .= "    ".$_."\n";
          }
          $found = 1;
          last;
        }
      }
      # now search for the last spin
      my $last_spin = ($type eq "pol") ? ${$der_order}[-1][1] : ${$der_order}[0][1];
      if(/^\s*$last_spin\s*=/){
        $new_c_code .= "  if(order < ".($total_order+1).") return;\n\n\n"
      }
    }

    if(($found == 0) && ($_ =~ /^(t\d+) =/)){
      if($n_var % 8 == 0){
        $variables .= ";\n" if($n_var != 0);
        $variables .= "  double ";
      }else{
        $variables .= ", ";
      }
      $n_var++;

      $variables .= "$1";
      $new_c_code .= "  ".$_;
    }elsif($found == 0){
      $new_c_code .= "  ".$_;
    }	
  }
  $variables .= ";\n" if($n_var != 0);

  return ($variables, maple2c_replace($new_c_code));
}

sub maple2c_replace {
  # The replacements have to be made in order, so
  # we can not use a hash table
  my @math_replace = (
    qr/_s_/,                            q{"*"},
    qr/_a_/,                            q{"->"},
    qr/_d_/,                            q{"."},
    qr/_(\d+)_/,                        q{"[$1]"},
    # have to do it here, as both Dirac(x) and Dirac(n, x) can appear
    qr/Dirac\(.*?\)/,                   q{"0.0"},
    # the derivative of the signum is 0 for us
    qr/signum\(1.*\)/,                  q{"0.0"},
    # optimizing specific calls to pow (sometimes we need to be careful with nested parenthesis)
    qr/pow\(0.1e1, (?:\(.*?\)|[^\(])*?\)/,        q{"0.1e1"},
    qr/pow\((.*?), *0.10*e1\)/,                   q{"($1)"},
    qr/pow\((.*?), *-0.10*e1\)/,                  q{"0.1e1/($1)"},
    qr/pow\((.*?), *0.15e1\)/,                    q{"POW_3_2($1)"},
    qr/pow\((.*?), *-0.15e1\)/,                   q{"0.1e1/POW_3_2($1)"},
    qr/pow\((.*?), *0.20*e1\)/,                   q{"POW_2($1)"},
    qr/pow\((.*?), *-0.20*e1\)/,                  q{"0.1e1/POW_2($1)"},
    qr/pow\((.*?), *0.30*e1\)/,                   q{"POW_3($1)"},
    qr/pow\((.*?), *-0.30*e1\)/,                  q{"0.1e1/POW_3($1)"},
    qr/pow\((.*?), *0.50*e0\)/,                   q{"sqrt($1)"},
    qr/pow\((.*?), *-0.50*e0\)/,                  q{"0.1e1/sqrt($1)"},
    qr/pow\((.*?), *0.1e1 \/ 0.3e1\)/,            q{"POW_1_3($1)"},
    qr/pow\((.*?), *-0.1e1 \/ 0.3e1\)/,           q{"0.1e1/POW_1_3($1)"},
    qr/pow\((.*?), *0.1e1 \/ 0.4e1\)/,            q{"POW_1_4($1)"},
    qr/pow\((.*?), *-0.1e1 \/ 0.4e1\)/,           q{"0.1e1/POW_1_4($1)"},
    qr/pow\((.*?), *0.666666666666666666.e0\)/,   q{"POW_2_3($1)"},
    qr/pow\((.*?), *-0.666666666666666666.e0\)/,  q{"0.1e1 / POW_2_3($1)"},
    qr/pow\((.*?), *0.333333333333333333.e0\)/,   q{"POW_1_3($1)"},
    qr/pow\((.*?), *-0.333333333333333333.e0\)/,  q{"0.1e1 / POW_1_3($1)"},
    qr/pow\((.*?), *0.1333333333333333333.e1\)/,  q{"POW_4_3($1)"},
    qr/pow\((.*?), *-0.1333333333333333333.e1\)/, q{"0.1e1 / POW_4_3($1)"},
    qr/pow\((.*?), *0.1666666666666666666.e1\)/,  q{"POW_5_3($1)"},
    qr/pow\((.*?), *-0.1666666666666666666.e1\)/, q{"0.1e1 / POW_5_3($1)"},
    qr/pow\((.*?), *0.2333333333333333333.e1\)/,  q{"POW_7_3($1)"},
    qr/pow\((.*?), *-0.2333333333333333333.e1\)/, q{"0.1e1 / POW_7_3($1)"},
    # cleaning up constant expressions
    qr/0.31415926535897932385e1/,                 q{"M_PI"},
    qr/sqrt\(0.2e1\)/,                            q{"M_SQRT2"},
    qr/POW_1_3\(0.2e1\)/,                         q{"M_CBRT2"},
    qr/POW_1_3\(0.3e1\)/,                         q{"M_CBRT3"},
    qr/POW_1_3\(0.4e1\)/,                         q{"M_CBRT4"},
    qr/POW_1_3\(0.5e1\)/,                         q{"M_CBRT5"},
    qr/POW_1_3\(0.6e1\)/,                         q{"M_CBRT6"},
    qr/POW_1_3\(M_PI\)/,                          q{"M_CBRTPI"},
  );
  my ($text) = @_;

  # _s_zk unfortunatly appears in some expressions
  if($text =~ /_s_zk = (.*);/m){
    my $zk = $1;
    $text =~ s/_s_zk(?! =)/($zk)/g;
  }
  
  for(my $j=0; $j<$#math_replace; $j+=2){
    $text =~ s/$math_replace[$j]/$math_replace[$j+1]/eeg;
  }

  return $text;
}

sub maple2c_construct_arguments
{
  my ($variables, $derivatives) = @_;

  # construct the arguments of the function
  my ($input_args, $last_arg) = "";
  foreach my $arg (@{$variables}){
    $arg =~ s/_.*$//;

    next if($arg eq $last_arg);
    $last_arg = $arg;
      
    $input_args .= ", " if $input_args ne "";
    $input_args .= "const double *$arg";
  }
  
  my ($output_args, $last_arg) = ("", "");
  foreach my $der_order (@{$derivatives}){
    foreach my $der (@{$der_order}){
      my $arg = ${$der}[1];
      $arg = "*".$arg if(! ($arg =~ s/_s_/*/g));
      $arg =~ s/_.*$//;

      next if($arg eq $last_arg);
      $last_arg = $arg;
      
      $output_args .= ", " if $output_args ne "";
      $output_args .= "double $arg";
    }
  }
  return ($input_args, $output_args);
}

sub maple2c_print_header
{
  my ($out) = @_;
  
  my $maple_version = `echo -e "quit;" | maple 2>&1 | head -n 1 | sed 's/^.*Maple/Maple/'`;
  chomp $maple_version;
  print $out "/* 
  This file was generated automatically with $0.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : $maple_version
  Maple source      : $config{'mathfile'}
  Type of functional: $config{'functype'}
*/

#define maple2c_order $config{'max_order'}
";
}

sub maple2c_run
{
  my ($variables, $derivatives, $variants, $start_order) = @_;
  
  # get arguments of the functions
  my ($input_args, $output_args) = maple2c_construct_arguments($variables, $derivatives);
  
  # open file to write to
  my $fname = $config{'srcdir'}."/src/maple2c/".
      $config{'functype'}."/".$config{'functional'}.".c";
  open my $out, '>', $fname or die "Could not open file $fname for writing\n";
  maple2c_print_header($out, $config{'mathfile'}, 
                       $config{'functype'}, $config{'max_order'});

  for(my $j=0; $j<$#{$variants}; $j+=2){
    ($vars_def, $c_code) = maple2c_run_maple(${$variants}[$j], 
                ${$variants}[$j+1], $derivatives, $start_order);

    print $out "
static inline void
func_${$variants}[$j](const xc_func_type *p, int order, $input_args, $output_args)
{
$vars_def
$config{'prefix'}
$c_code
}

";
  }
  close($out);
}
