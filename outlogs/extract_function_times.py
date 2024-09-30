import re
import numpy as np

# Function to extract and print times along with the descriptive text
def extract_and_print_times(log_file):
    # Regular expression to match the relevant lines and extract the time
    pattern = re.compile(r'#KALANINJA:(.*): (\d+\.\d+) seconds')

    with open(log_file, 'r') as file:
        for line in file:
            match = pattern.search(line)
            if match:
                # Extract the text (ignoring #KALANINJA) and the time
                description = match.group(1).strip()
                time_value = match.group(2)
                # Print the description and time
                print(f"{description}: {time_value} seconds")

if __name__ == "__main__":
    #log_file = 'cpu_out_1_2_10_10'  # Replace with your actual log file name
    cpuarr = ['1','2','4','8']
    maxvalarr = ['10','50','100','200']
    #log_files = np.array(['cpu_out_1_1_500_500','cpu_out_1_2_500_500','cpu_out_1_4_500_500','cpu_out_1_8_500_500'])
    #log_files = np.array(['cpu_out_1_1_50_50','cpu_out_1_2_50_50','cpu_out_1_4_50_50','cpu_out_1_8_50_50'])
    log_files = np.array(['cpu_out_1_1_300_300','cpu_out_1_4_300_300'])

    for log_file in log_files:
        print(log_file)
        extract_and_print_times(log_file)
