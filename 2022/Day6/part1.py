import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <file_path>")
    sys.exit(1)  

file_path = sys.argv[1]

try:
    with open(file_path, 'r') as file:
        line = file.readline()
        for i in range(0,len(line) - 14):
            sub = line[i:i+14]
            if len(set(sub)) == 14:
                print(14 + i)
                break

except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")