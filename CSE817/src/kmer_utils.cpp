#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include "kmer_utils.h"

// Function to count k-mers in a given sequence
void count_kmers(const std::string &sequence, int k, std::unordered_map<std::string, int> &kmer_counts) {
    for (size_t i = 0; i <= sequence.length() - k; ++i) {
        std::string kmer = sequence.substr(i, k);
        kmer_counts[kmer]++;
    }
}

// Function to process the FASTA file and extract top k frequent k-mers using a heap
void process_fasta_file_with_heap(const std::string &file_name, int k, int top_k, const std::string &output_file) {
    std::ifstream fasta_file(file_name);
    if (!fasta_file.is_open()) {
        std::cerr << "Error opening file: " << file_name << std::endl;
        return;
    }

    std::unordered_map<std::string, int> kmer_counts;
    std::string line, sequence;
    
    // Skip FASTA header lines and concatenate sequences
    while (std::getline(fasta_file, line)) {
        if (line[0] == '>') continue;  // Skip header lines
        sequence += line;
    }

    // Count k-mers in the entire sequence
    count_kmers(sequence, k, kmer_counts);

    // Use a max-heap to extract top k frequent k-mers
    auto cmp = [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
        return a.second < b.second;
    };
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(cmp)> heap(cmp);

    for (const auto &entry : kmer_counts) {
        heap.push(entry);
        if (heap.size() > top_k) {
            heap.pop();
        }
    }

    // Write the top k k-mers to the output file
    std::ofstream out_file(output_file);
    if (!out_file.is_open()) {
        std::cerr << "Error opening output file: " << output_file << std::endl;
        return;
    }

    out_file << "Top " << top_k << " frequent k-mers:" << std::endl;
    while (!heap.empty()) {
        auto kmer = heap.top();
        out_file << kmer.first << "," << kmer.second << std::endl;
        heap.pop();
    }

    std::cout << "Results written to " << output_file << std::endl;
}
