import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <file_path>")
    sys.exit(1)  

file_path = sys.argv[1]

def priority(c):
    if c.isupper():
        return ord(c) - 64 + 26
    elif common.islower():
        return ord(c) - 96

try:
    with open(file_path, 'r') as file:
        result = 0
        lines = [line.strip() for line in file]

        for i in range(0, len(lines), 3):
            common = set(lines[i]) & set(lines[i+1]) & set(lines[i+2])
            common = ''.join(common)
            result += priority(common)
        print(result)
            

except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")