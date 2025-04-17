CXX = g++
CXXFLAGS = -O3 -std=c++17 -fopenmp
INCLUDE = -Iinclude
SRC = src/main.cpp src/kmer_utils.cpp
OBJ = main.o kmer_utils.o
TARGET = kmer_parallel

# Build the target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Compile the source files
main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/main.cpp -o main.o

kmer_utils.o: src/kmer_utils.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/kmer_utils.cpp -o kmer_utils.o

# Clean up
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run:
	./$(TARGET) data/Homo_sapiens.GRCh38.dna.chromosome.1.fa 6 20 results_with_heap.txt

