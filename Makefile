CXX = g++
CXXFLAGS = -O3 -std=c++17
INCLUDES = -Iinclude
SRC = src/main.cpp src/kmer_utils.cpp
OUT = kmer_parallel
OUT_NO_OPENMP = kmer_parallel_no_omp

# With OpenMP
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -fopenmp $(INCLUDES) -o $(OUT)

# Without OpenMP
no_openmp: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(INCLUDES) -o $(OUT_NO_OPENMP)

# Clean build
clean:
	rm -f $(OUT) $(OUT_NO_OPENMP)

