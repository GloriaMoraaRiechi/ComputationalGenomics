#ifndef KMER_UTILS_H
#define KMER_UTILS_H

#include <string>
#include <unordered_map>

// Function to count k-mers in a sequence
void count_kmers(const std::string &sequence, int k, std::unordered_map<std::string, int> &kmer_counts);

// Function to process the FASTA file and count k-mers with heap-based extraction of top k
void process_fasta_file_with_heap(const std::string &file_name, int k, int top_k, const std::string &output_file);

#endif // KMER_UTILS_H

