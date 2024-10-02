#!/bin/bash
#source /opt/intel/oneapi/setvars.sh
export NUMHARM=1
#export NUMCPUS=8
#export ZMAX=10
#export WMAX=10
export DATFILE="./executions/G0057_1368033096_15:43:38.82_+09:29:16.30_ch109-132_0001.fits_DM50.00.dat"
export ACCELSEARCH_GCC="./build_gcc/src/accelsearch"
export ACCELSEARCH_CLANG="./build_clang/src/accelsearch"

for NUMCPUS in 1 4 8
do
    #for MAXVAL in 10 50 100 200 500
    for MAXVAL in 300
    do

        ZMAX=$MAXVAL
        WMAX=$MAXVAL
        OUTNAME="gcc_out_${NUMHARM}_${NUMCPUS}_${WMAX}_${ZMAX}"
        ${ACCELSEARCH_GCC} -numharm ${NUMHARM} -ncpus ${NUMCPUS} -zmax ${ZMAX} -wmax ${WMAX} ${DATFILE} > gcc_clang_outlogs/${OUTNAME}
        OUTNAME="clang_out_${NUMHARM}_${NUMCPUS}_${WMAX}_${ZMAX}"
        ${ACCELSEARCH_CLANG} -numharm ${NUMHARM} -ncpus ${NUMCPUS} -zmax ${ZMAX} -wmax ${WMAX} ${DATFILE} > gcc_clang_outlogs/${OUTNAME}
        
    done
done