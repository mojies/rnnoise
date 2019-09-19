#!/bin/bash

cd ../src; ./compile.sh; cd -

FILE_SIZE=$(stat --printf="%s" /share/tmp/singnal.pcm)
let COUNT=${FILE_SIZE}/960
# COUNT=$(./get.batch.numbers.py)
echo "batch numbers: ${COUNT}"

umask 000
MATRIX_SIZE=$(../src/denoise_training /share/tmp/singnal.pcm /share/tmp/noise.pcm /share/tmp/training.f32 ${COUNT})
ROW_SIZE=$(echo $MATRIX_SIZE | awk '{print $3}')
echo ${ROW_SIZE}
sync
./bin2hdf5.py /share/tmp/training.f32 ${ROW_SIZE} 87 ../data/training.h5

