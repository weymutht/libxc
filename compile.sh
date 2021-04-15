#!/bin/bash

set -e

module load maple/2018.1
module load perl/5.30.2

libxcDir=${HOME}/code/libxc
mapleDir=${HOME}/code/libxc/maple
cd ${mapleDir}/gga_exc
## Create C code of GWS and helper functionals from Maple code
../../scripts/maple2c.pl ../.. gga_c_gws 4
../../scripts/maple2c.pl ../.. gga_x_gws 4
cd ${mapleDir}/lda_exc
../../scripts/maple2c.pl ../.. lda_c_pmgb06 4
../../scripts/maple2c.pl ../.. lda_x_erf_jt 4
cd ${libxcDir}

#cd ${mapleDir}/gga_exc
#../../scripts/maple2c.pl ../.. gga_c_pbehseri 4   # Takes about 44 minutes on tc-ws-006
#cd ${mapleDir}/lda_exc
#../../scripts/maple2c.pl ../.. lda_c_pmgb06 4
#../../scripts/maple2c.pl ../.. lda_x_erf 4
#cd ${libxcDir}

# Create C code for references
cd ${libxcDir}/src
../scripts/get_references.pl ../libxc.bib
cd ${libxcDir}

# Compile, test, and install library; clean up afterwards
#autoreconf -i -v
##./configure --prefix=/fast_scratch/vvburg/cache/libxc/inst
./configure --prefix=/home/cds/vvburg/code/libxc/inst
make -j 4
make check
make install
make clean
make distclean

#cd build_test
#cmake DCMAKE_BUILD_TYPE=RELEASE -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=../inst ..
#make -j 6
#make check
#make install
#make clean
