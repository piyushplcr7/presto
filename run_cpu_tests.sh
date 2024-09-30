#!/bin/bash

export NUMHARM=1
#export NUMCPUS=8
#export ZMAX=10
#export WMAX=10
export DATFILE="./executions/G0057_1368033096_15:43:38.82_+09:29:16.30_ch109-132_0001.fits_DM50.00.dat"

for NUMCPUS in 4
do
    #for MAXVAL in 10 50 100 200 500
    for MAXVAL in 300
    do

        ZMAX=$MAXVAL
        WMAX=$MAXVAL
        OUTNAME="cpu_out_${NUMHARM}_${NUMCPUS}_${WMAX}_${ZMAX}"
        /opt/AMDuProf_4.2-850/bin/AMDuProf collect --profile tbp -o outlogs accelsearch -numharm ${NUMHARM} -ncpus ${NUMCPUS} -zmax ${ZMAX} -wmax ${WMAX} ${DATFILE} #> outlogs/${OUTNAME}
    done
done