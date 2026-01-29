#!/usr/bin/env bash

make # Compile and link helloNr
N=10 # Number of jobs

for ((i=1; i<=N; i++)); do
    RAND=$((RANDOM % 100 + 1)) # Generate random input number
    make run ARG=$RAND > output_job${i}.txt &
done

wait
make cleanAll # Clean up files