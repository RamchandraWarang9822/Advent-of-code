import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <file_path>")
    sys.exit(1)  

file_path = sys.argv[1]

try:
    with open(file_path, 'r') as file:
        for line in file:
            line = line.strip()
            print(line)

except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")