import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

def plot_kmer_heatmap(input_file):
    # Read the k-mer data from the CSV file
    df = pd.read_csv(input_file)
    
    # If you want a simple plot of kmer vs frequency, you can directly create a barplot
    # or heatmap-like visualization, where the rows represent kmers, and columns represent frequency.
    df_sorted = df.sort_values(by="frequency", ascending=False)
    
    # Reshape the data (optional if you want to do something more advanced)
    # For now, we'll just visualize the top 20 k-mers as a barplot.
    top_kmers = df_sorted.head(20)

    # Create a barplot (you can use a heatmap if you have more advanced structure)
    plt.figure(figsize=(12, 8))
    sns.barplot(x="frequency", y="kmer", data=top_kmers, palette="viridis")
    
    # Save the plot as an image
    plt.savefig("kmer_heatmap.png")

    # Show the plot
    plt.show()

if __name__ == "__main__":
    import sys
    input_file = sys.argv[1]  # Get the input CSV file from command line argument
    plot_kmer_heatmap(input_file)

