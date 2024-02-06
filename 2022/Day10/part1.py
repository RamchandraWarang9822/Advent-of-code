import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <file_path>")
    sys.exit(1)  

file_path = sys.argv[1]
cycle = 1
check = [20,60,100,140,180,220]
result = 0
x = 1

def draw_pixel(cycle, x):
    current = (cycle % 40)
    if current >= x and current < x+3:
        print("#", end='')
    else:
        print("o", end='')
        
    if current == 0:
        print("\n", end='')
    
    

try:
    with open(file_path, 'r') as file:
        for line in file:
            line = line.strip()
            line = line.split()
            if len(line) > 1:
                draw_pixel(cycle, x)
                cycle += 1
                if cycle in check:
                    product = cycle * x
                    result += product
                draw_pixel(cycle, x)
                cycle += 1
                x += int(line[1])
            else:
                draw_pixel(cycle, x)
                cycle += 1
            if cycle in check:
                product = cycle * x
                result += product
            
        print(result)

except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")