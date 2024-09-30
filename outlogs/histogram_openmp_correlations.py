import re
import matplotlib.pyplot as plt
import numpy as np

# Function to extract times from the log file
def extract_times(log_file):
    times = []
    # Regular expression to match the time in the format "0.000XXX seconds"
    pattern = re.compile(r'(\d+\.\d+) seconds')
    
    with open(log_file, 'r') as file:
        for line in file:
            match = pattern.search(line)
            if match:
                # Convert the extracted time to float and append to the list
                times.append(float(match.group(1)))
    
    return times

# Function to plot the histogram with better bins
def plot_histogram(times):
    # Automatically determine number of bins (can adjust this)
    num_bins = 10  # Default number of bins
    
    # Optionally, you can control bin width more explicitly by using np.arange
    bin_width = 0.00001  # Adjust the bin width based on your data range
    print("Min(times) = ", min(times))
    print("Max(times) = ", max(times))
    bins = np.arange(min(times), max(times) + bin_width, bin_width)

    plt.hist(times, bins=bins, edgecolor='black')
    plt.xlabel('Time (seconds)')
    plt.ylabel('Frequency')
    plt.title('Histogram of Correlation Times')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    #log_file = 'cpu_out_1_1_10_10'  # Replace with your actual log file name
    log_files = np.array(['cpu_out_1_1_10_10','cpu_out_1_2_10_10','cpu_out_1_4_10_10','cpu_out_1_8_10_10'])
    
    
    times = extract_times(log_file)
    
    if times:
        plot_histogram(times)
    else:
        print("No correlation times found in the log file.")
