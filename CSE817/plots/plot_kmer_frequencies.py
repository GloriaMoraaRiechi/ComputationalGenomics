import pandas as pd
import matplotlib.pyplot as plt

def plot_kmer_frequencies(input_file):
    # Load the k-mer frequencies from the CSV file
    kmer_data = pd.read_csv(input_file, header=None, names=["K-mer", "Frequency"])
    
    # Sort the data by frequency in descending order
    kmer_data = kmer_data.sort_values(by="Frequency", ascending=False)
    
    # Plot the top 20 k-mers
    plt.figure(figsize=(10, 6))
    plt.barh(kmer_data["K-mer"][:20], kmer_data["Frequency"][:20], color='skyblue')
    plt.xlabel('Frequency')
    plt.ylabel('K-mer')
    plt.title('Top 20 Frequent K-mers')
    plt.gca().invert_yaxis()  # To display the highest frequency at the top
    plt.tight_layout()
    
    # Show the plot
    plt.show()

# Run the plot function
if __name__ == "__main__":
    plot_kmer_frequencies("results_human_chr1.txt")  # Change to the appropriate file

