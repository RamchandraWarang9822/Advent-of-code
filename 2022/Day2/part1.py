import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <file_path>")
    sys.exit(1)

file_path = sys.argv[1]

def points(c):
    if c == 'A': #ROCK
        return 1
    elif c == 'B': #PAPER
        return 2
    elif c == 'C': #SCISSOR
        return 3

def choice(opp, output):
    if output == 'Y': #DRAW
        return opp + 3
    elif output == 'X': #LOSE
        return (3 if opp == 1 else opp - 1)
    elif output == 'Z': #WIN
        return (1 if opp == 3 else opp + 1) + 6

try:
    result = 0
    with open(file_path, 'r') as file:
        for line in file:
            arr = line.split() 
            opp = points(arr[0])
            output = arr[1]
            result += choice(opp, output)
            print(result)

            
except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")