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

        """
        Idea to solve Day 7 
        1. Using Tree and storing all the directories and file and later traverse and 
           calculate the directory size
        2. Store each directory as an array within the array store the files and folders 
           within and with files store the size and name then later traverse the arrays and calculate the size

           ----------------------------------------------------------------------------
           struct file{
                string name
                int size
           }

           array<array<file> = [[]]
           ----------------------------------------------------------------------------
        """

except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")