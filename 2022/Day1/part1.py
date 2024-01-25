import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <file_path>")
    sys.exit(1)  

file_path = sys.argv[1]

try:
    with open(file_path, 'r') as file:
        current = 0
        list = []

        for line in file:
            if line == '\n':
                list.append(current)
                current = 0
            else:
                current += int(line)
        list.append(current)

        print(*list)
        list.sort()
        print(*list)

        result = sum(list[-3:])
    print(result)

except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")
