import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import sys

if len(sys.argv) < 2:
    print("Usage: python kmer_heatmap.py <input_csv>")
    sys.exit(1)

data = pd.read_csv(sys.argv[1], header=None, names=["kmer", "count"])
top_kmers = data.sort_values(by="count", ascending=False)

plt.figure(figsize=(10, 6))
sns.barplot(x="count", y="kmer", data=top_kmers, palette="viridis")
plt.title("Top k-mers")
plt.tight_layout()
plt.savefig("plots/kmer_barplot.png")
print("Plot saved to plots/kmer_barplot.png")

