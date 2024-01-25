import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <file_path>")
    sys.exit(1)  

file_path = sys.argv[1]

try:
    with open(file_path, 'r') as file:
        result = 0
        for line in file:
            line = line.strip()
            mid = len(line) // 2
            common = set(line[:mid]) & set(line[mid:])
            common = ''.join(common)
            priority = 0
            if common.isupper():
                priority = ord(common) - 64 + 26
            elif common.islower():
                priority = ord(common) - 96

            result += priority
        print(result)
            

except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")