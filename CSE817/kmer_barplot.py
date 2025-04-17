import pandas as pd
import matplotlib.pyplot as plt

# Function to plot the bar plot of top k-mers by frequency
def plot_kmer_barplot(input_file, top_k=20):
    # Read the data
    df = pd.read_csv(input_file, header=None, names=["kmer", "frequency"])

    # Convert frequency column to numeric
    df['frequency'] = pd.to_numeric(df['frequency'], errors='coerce')

    # Sort the DataFrame by frequency and select top_k
    df_sorted = df.sort_values(by="frequency", ascending=False).head(top_k)

    # Plot the bar plot
    plt.figure(figsize=(10, 6))
    plt.bar(df_sorted['kmer'], df_sorted['frequency'], color='skyblue')
    plt.xlabel('K-mer')
    plt.ylabel('Frequency')
    plt.title(f'Top {top_k} K-mers by Frequency')
    plt.xticks(rotation=90)
    plt.tight_layout()  # Adjust layout to prevent clipping
    plt.show()

    # Optionally, save the plot as an image
    plt.savefig("kmer_barplot.png")

# Example usage
input_file = "results_with_omp.txt"
plot_kmer_barplot(input_file)

