#!/bin/bash

# Parameters
KMER=6
TOPK=20

mkdir -p logs

echo "Running OpenMP version with 8 threads..."
export OMP_NUM_THREADS=8
/usr/bin/time -v ./kmer_parallel data/Homo_sapiens.GRCh38.dna.chromosome.1.fa $KMER $TOPK \
  > results_with_omp.txt 2> logs/time_with_omp.txt

echo "Running non-OpenMP version..."
/usr/bin/time -v ./kmer_parallel_no_omp data/Homo_sapiens.GRCh38.dna.chromosome.1.fa $KMER $TOPK \
  > results_no_omp.txt 2> logs/time_no_omp.txt

echo "Benchmarking complete!"

