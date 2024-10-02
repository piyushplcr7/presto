import re
import matplotlib.pyplot as plt
import numpy as np

# Function to extract the time values from each line
def extract_times(file_path, section):
    times = []
    with open(file_path, 'r') as file:
        for line in file:
            match = re.search(r"Thread : 0 spent (\d+\.\d+) " + section, line)
            if match:
                times.append(float(match.group(1)))
    return times

# File path to your log file
single_thread = 'cpu_out_1_1_300_300'  # Replace with your actual file path
four_thread = 'cpu_out_1_4_300_300'

# Extract times from the file
section = "seconds on power calc"
section = "seconds on complex mult"
times1 = extract_times(single_thread, section)
times1 = np.array(times1)
print("Single thread mean time: ",np.mean(times1))
print("Single thread time stdev:", np.std(times1))

times4 = extract_times(four_thread, section)
times4 = np.array(times4)
print("Four threads mean time: ",np.mean(times4))
print("Four threads time stdev:", np.std(times4))

# Create a histogram
""" plt.hist(times1, bins=10, edgecolor='black')
plt.xlabel('Time (seconds)')
plt.ylabel('Frequency')
plt.title('Histogram for 1 thread')

plt.figure()
plt.hist(times4, bins=10, edgecolor='black')
plt.xlabel('Time (seconds)')
plt.ylabel('Frequency')
plt.title('Histogram for 4 threads')

plt.show() """
