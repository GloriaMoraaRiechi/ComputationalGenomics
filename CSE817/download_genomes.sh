#!/bin/bash

# Create data directory if not exists
mkdir -p data

# URLs to download
human_url="https://ftp.ensembl.org/pub/release-111/fasta/homo_sapiens/dna/Homo_sapiens.GRCh38.dna.chromosome.1.fa.gz"
mouse_url="https://ftp.ensembl.org/pub/release-111/fasta/mus_musculus/dna/Mus_musculus.GRCm39.dna.chromosome.1.fa.gz"

# Download genome files
echo "Downloading Human Chromosome 1..."
wget -P data/ "$human_url"

echo "Downloading Mouse Chromosome 1..."
wget -P data/ "$mouse_url"

# Unzip files
echo "Unzipping files..."
gunzip -f data/*.fa.gz

echo "Done! FASTA files are in the 'data/' folder."

