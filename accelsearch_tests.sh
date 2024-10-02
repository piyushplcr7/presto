#!/bin/bash
export ACCELSEARCH_GCC="./build_gcc/src/accelsearch_test"
export ACCELSEARCH_CLANG="./build_clang/src/accelsearch_test"

for NUMCPUS in 1 2 4 8
do
    export OMP_NUM_THREADS=${NUMCPUS}
    for MAXVAL in 300
    do
        OUTNAME="gcc_out_${NUMCPUS}"
        ${ACCELSEARCH_GCC} > accelsearch_test_outlogs/${OUTNAME}
        OUTNAME="clang_out_${NUMCPUS}"
        ${ACCELSEARCH_CLANG} > accelsearch_test_outlogs/${OUTNAME}
        
    done
done