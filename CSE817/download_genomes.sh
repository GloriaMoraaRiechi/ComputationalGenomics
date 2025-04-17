#!/bin/bash

# Create data directory if it doesn't exist
mkdir -p data

# Updated URLs to download from Ensembl release 111
human_url="https://ftp.ensembl.org/pub/release-111/fasta/homo_sapiens/dna/Homo_sapiens.GRCh38.dna.primary_assembly.fa.gz"
mouse_url="https://ftp.ensembl.org/pub/release-111/fasta/mus_musculus/dna/Mus_musculus.GRCm39.dna.primary_assembly.fa.gz"

# Download genome files
echo "Downloading full Human genome (GRCh38)..."
wget -P data/ "$human_url"

echo "Downloading full Mouse genome (GRCm39)..."
wget -P data/ "$mouse_url"

# Unzip files
echo "Unzipping files..."
gunzip -f data/*.fa.gz

echo "Done! Full FASTA files are in the 'data/' folder."

