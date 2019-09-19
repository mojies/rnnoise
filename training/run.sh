#!/bin/bash

set +e
# LD_LIBRARY_PATH=/opt/cuda/lib64 ./rnn_train.py
LD_LIBRARY_PATH=/opt/cuda/lib64 ./rnn_train.tensorboard.py

./dump_rnn.py weights.final.hdf5 ../src/rnn_data.c ../src/rnn_data.h orig
