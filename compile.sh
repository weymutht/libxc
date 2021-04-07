#!/bin/bash

set -e

module load maple/2018.1
module load perl/5.30.2

mapleDir=${HOME}/code/libxc/maple
#cd ${mapleDir}/gga_exc
## Create C code of GWS from Maple code
#../../scripts/maple2c.pl ../.. gga_c_gws 4
#../../scripts/maple2c.pl ../.. gga_x_gws 4
#cd ${mapleDir}/lda_exc
#../../scripts/maple2c.pl ../.. lda_c_pmgb06 4
#../../scripts/maple2c.pl ../.. lda_x_erf_jt 4
#cd ../../

#cd ${mapleDir}/gga_exc
#../../scripts/maple2c.pl ../.. gga_c_pbehseri 4   # Takes about 44 minutes on tc-ws-006
#cd ../lda_exc
#cd ${mapleDir}/lda_exc
#../../scripts/maple2c.pl ../.. lda_c_pmgb06 4
#../../scripts/maple2c.pl ../.. lda_x_erf 4
#cd ../..

# Create C code for references
cd src
../scripts/get_references.pl ../libxc.bib
cd ..

# Compile, test, and install library; clean up afterwards (takes about 4 minutes on tc-ws-006)
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
