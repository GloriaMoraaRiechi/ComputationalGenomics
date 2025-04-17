#include <iostream>
#include <unordered_map>
#include <omp.h>
#include <fstream>
#include "kmer_utils.h"

int main(int argc, char* argv[]) {
    if (argc < 5) {
        std::cerr << "Usage: " << argv[0] << " <fasta_file> <k> <top_k> <output_file>\n";
        return 1;
    }

    std::string fasta_file = argv[1];
    int k = std::stoi(argv[2]);       // length of each k-mer
    int top_k = std::stoi(argv[3]);   // how many top k-mers to save
    std::string output_file = argv[4];

    std::cout << "Reading FASTA file...\n";
    std::string sequence = read_fasta(fasta_file);
    size_t n = sequence.size();
    std::unordered_map<std::string, int> kmer_map;

    std::cout << "Counting k-mers using OpenMP...\n";
    #pragma omp parallel
    {
        std::unordered_map<std::string, int> local_map;

        #pragma omp for nowait
        for (size_t i = 0; i <= n - k; ++i) {
            std::string kmer = sequence.substr(i, k);
            #pragma omp critical
            {
                kmer_map[kmer]++;
            }
        }
    }

    std::cout << "Extracting top " << top_k << " most frequent k-mers...\n";
    auto top_kmers = get_top_k_kmers(kmer_map, top_k);

    std::cout << "Saving results to " << output_file << "...\n";
    save_kmers_to_file(top_kmers, output_file);

    std::cout << "Done. You can now visualize using the Python script.\n";
    return 0;
}
