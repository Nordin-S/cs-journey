import matplotlib.pyplot as plt
import numpy as np
import os

# Set the directory where the CSV files are located
directory = "cmake-build-debug"

# Loop through the CSV files in the directory
for filename in os.listdir(directory):
    if filename.endswith(".csv"):
        # Read the data from the CSV file
        sizes, times, stddevs, sample_sizes = [], [], [], []
        with open(os.path.join(directory, filename)) as f:
            for line in f:
                if line.startswith("#"):
                    continue
                size, time, stddev, sample_size = line.strip().split(",")
                sizes.append(int(size))
                times.append(float(time))
                stddevs.append(float(stddev))
                sample_sizes.append(int(sample_size))

        # Fit a polynomial to the data
        z = np.polyfit(sizes, times, 2)
        f = np.poly1d(z)

        # Generate a smooth curve for the fitted polynomial
        sizes_fine = np.linspace(sizes[0], sizes[-1], 100)
        times_fine = f(sizes_fine)

        # Plot the data
        plt.errorbar(sizes, times, yerr=stddevs, fmt="o", label="Fit Data")
        plt.plot(sizes_fine, times_fine, label="Fit k N^2")
        plt.title(filename)
        plt.xlabel("N elements")
        plt.ylabel("t [ms]")
        plt.legend(loc="upper center")
        plt.grid()
        # plt.show()
        plt.savefig(filename + ".png")
        plt.clf()
        plt.close()
