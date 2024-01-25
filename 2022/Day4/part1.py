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
            
            one, two = line.split(',')
            s1, e1 = map(int, one.split('-'))
            s2, e2 = map(int, two.split('-'))
            my_set = set(range(s1, e1 + 1))
            
            for i in range(s2, e2 + 1):
                if i in my_set:
                    result += 1
                    break
                    
        print(result)
except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")