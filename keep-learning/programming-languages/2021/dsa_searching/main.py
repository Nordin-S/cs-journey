import matplotlib.pyplot as plt
import numpy as np
import os

# Set the directory where the CSV files are located
directory = "cmake-build-release"

print(f"dir: {directory}")
# # Loop through the CSV files in the directory
for filename in os.listdir(directory):
    if filename.endswith(".csv"):
        print(f"Reading: {filename}")
        # Read the data from the CSV file
        sizes, times, stddevs, sample_sizes = [], [], [], []
        location = "cmake-build-release/"
        # filename = "selection_sort_RandomData"
        # with open(location + filename + ".csv") as f:
        # open file using os and filename
        with open(os.path.join(location, filename), 'r') as f:
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
        plt.plot(sizes_fine, times_fine, label="Fit ---")
        plt.title(filename)
        plt.xlabel("N elements")
        plt.ylabel("t [ms]")
        plt.legend(loc="upper center")
        plt.grid()
        plt.axis([0, None, 0, None])
        # plt.show()
        plt.savefig(filename + ".png")
        plt.clf()
        plt.close()
