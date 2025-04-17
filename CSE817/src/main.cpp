#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <functional>
#include "kmer_utils.h"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <input_fasta_file> <kmer_length> <top_k>" << std::endl;
        return 1;
    }

    // Declare variables
    std::string fasta_file = argv[1];  // Input FASTA file
    int kmer_length = std::stoi(argv[2]);  // K-mer length
    int top_k = std::stoi(argv[3]);  // Number of top k-mers to retrieve

    std::string output_file = "results_with_heap.txt";  // Output file name

    // Call the heap-based k-mer counting function
    process_fasta_file_with_heap(fasta_file, kmer_length, top_k, output_file);

    std::cout << "Top " << top_k << " frequent k-mers saved to " << output_file << std::endl;

    return 0;
}

