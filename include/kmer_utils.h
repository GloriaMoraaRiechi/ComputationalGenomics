#ifndef KMER_UTILS_H
#define KMER_UTILS_H

#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

std::string read_fasta(const std::string& filename);
std::vector<std::pair<std::string, int>> get_top_k_kmers(
    const std::unordered_map<std::string, int>& kmer_map, int k);
void save_kmers_to_file(const std::vector<std::pair<std::string, int>>& kmers,
                        const std::string& output_file);
std::string get_filename(const std::string& path);

#endif

