#include "kmer_utils.h"
#include <fstream>
#include <sstream>
#include <queue>
#include <algorithm>
#include <filesystem>

std::string read_fasta(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream ss;
    std::string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '>') continue;
        ss << line;
    }
    return ss.str();
}

std::vector<std::pair<std::string, int>> get_top_k_kmers(
    const std::unordered_map<std::string, int>& kmer_map, int k) {
    
    using Pair = std::pair<int, std::string>;
    auto cmp = [](Pair a, Pair b) { return a.first > b.first; };
    std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> min_heap(cmp);

    for (const auto& p : kmer_map) {
        min_heap.emplace(p.second, p.first);
        if (min_heap.size() > k)
            min_heap.pop();
    }

    std::vector<std::pair<std::string, int>> result;
    while (!min_heap.empty()) {
        result.emplace_back(min_heap.top().second, min_heap.top().first);
        min_heap.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

void save_kmers_to_file(const std::vector<std::pair<std::string, int>>& kmers,
                        const std::string& output_file) {
    std::ofstream out(output_file);
    for (const auto& p : kmers)
        out << p.first << "," << p.second << "\n";
}

std::string get_filename(const std::string& path) {
    return std::filesystem::path(path).stem().string();
}

