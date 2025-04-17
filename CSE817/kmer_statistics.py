import pandas as pd

# Read the CSV file containing k-mer data
def compute_statistics(input_file):
    df = pd.read_csv(input_file, header=None, names=["kmer", "frequency"])

    # Convert frequency column to numeric
    df['frequency'] = pd.to_numeric(df['frequency'], errors='coerce')

    # Calculate basic statistics
    mean_frequency = df['frequency'].mean()
    median_frequency = df['frequency'].median()
    std_dev_frequency = df['frequency'].std()

    print(f"Mean Frequency: {mean_frequency}")
    print(f"Median Frequency: {median_frequency}")
    print(f"Standard Deviation of Frequency: {std_dev_frequency}")

# Example usage
input_file = "results_with_omp.txt"
compute_statistics(input_file)

