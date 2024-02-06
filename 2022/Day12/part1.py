# import sys

# if len(sys.argv) != 2:
#     print("Usage: python script.py <file_path>")
#     sys.exit(1)  

# file_path = sys.argv[1]
file_path = 'Day12/test.txt'

# Data Structures 
lines = []
queue = []
start = []
end = []
visited = set()

def inbound(i, j):
    if i < 0 or i >= len(lines) or j < 0 or j >= len(lines[0]):
        return False
    else:
        return True

# Check if the coordinate is valid
def valid(from_i, from_j, to_i, to_j):
    if not (i < 0 and i > len(lines) and j < 0 and j > len(lines[0])):
        return False
    
    to_char = lines[to_i, to_j]
    to_char = 'z' if to_char == 'E' else to_char
    
    from_char = lines[from_i, from_j]
    to_char = 'a' if to_char == 'S' else to_char
    to = (to_i, to_j)
    
    return (to_char - from_char <= 1) and to not in visited


def get_neighbours(i, j, steps):
    
    neighbours = []
    if inbound(i, j - 1):
        neighbours.append([i, j-1, steps])
    if inbound(i-1,j):
        neighbours.append([i-1, j, steps])
    if inbound(i, j+1):
        neighbours.append([i, j+1, steps])
    if inbound(i+1,j):
        neighbours.append([i+1, j, steps])

    print(neighbours)
    return neighbours
    # del neighbours
    
try:
    with open(file_path, 'r') as file:
        # Convert to 2D array
        for line in file:
            line = line.strip()
            line = [i for i in line ]
            lines.append(line)
            del line
            
        for line in lines:
            print(line)
            del line

        # Find and store the Start and End coordinate
        for i in range(len(lines)):
            for j in range(len(lines[0])):
                if lines[i][j] == 'E':
                    end = [i, j]
                    print(end)
                if lines[i][j] == 'S':
                    start = [i, j]
                    print(start)

        del i,j

        queue.append(start + [0])
        visited.add((start[0],start[1]))

        while queue:
            current = queue.pop(0)
            print(current)
            i = current[0]
            j = current[1]
            steps = current[2]
            for each in get_neighbours(i, j, steps + 1):
                if(valid(i, j, each[0], each[1])):
                    visited.add((each[0],each[1]))
                    queue.append([each[0], each[1], steps + 1])
                    
            print(queue)
            
        
        # print(queue[0][2])    
        # if i == end[0] and j == end[1]:
        #     print(steps)
        # for each in get_neighbours(i, j, steps + 1):
        #     print(each)
        #     queue.append(each)
        #     del each

            

except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")