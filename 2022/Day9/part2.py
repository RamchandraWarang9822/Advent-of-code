# import sys

# if len(sys.argv) != 2:
#     print("Usage: python script.py <file_path>")
#     sys.exit(1)  

# file_path = sys.argv[1]
file_path = "input.txt"

visited = set()

list = [[0, 0] for _ in range(10)]

def updateHead(direction, x, y):
  if direction == 'U':
    y += 1
  elif direction == 'D':
    y -= 1
  elif direction == 'L':
    x -= 1
  elif direction == 'R':
    x += 1

  return x, y

def updateRope(x, y, tailX, tailY):
  if x - tailX >= 2 and y - tailY >= 1 or x - tailX >= 1 and y - tailY >= 2:
    tailX += 1
    tailY += 1
  elif x - tailX <= -2 and y - tailY <= -1 or x - tailX <= -1 and y - tailY <= -2:
    tailX -= 1
    tailY -= 1
  elif x - tailX >= 2 and y - tailY <= -1 or x - tailX >= 1 and y - tailY <= -2:
    tailX += 1
    tailY -= 1
  elif x - tailX <= -1 and y - tailY >= 2 or x - tailX <= -2 and y - tailY >= 1:
    tailX -= 1
    tailY += 1
  elif y - tailY >= 2:
    tailY += 1
  elif y -tailY <= -2:
    tailY -= 1
  elif x - tailX >= 2:
    tailX += 1
  elif x - tailX <= -2:
    tailX -= 1

  return tailX, tailY


try:
  with open(file_path, 'r') as file:
    visited.add((0,0))
    for line in file:
      line = line.strip()
      direction, steps = line.split()
      print(direction, steps)
      print(list)
      for i in range(int(steps)):
        list[0][0], list[0][1] = updateHead(direction, list[0][0], list[0][1])
        for j in range(1, len(list)):
          list[j][0], list[j][1] = updateRope(list[j-1][0], list[j-1][1], list[j][0], list[j][1])
          
        visited.add((list[9][0],list[9][1]))
        print(list[9][0], list[9][1])

    print(len(visited))

except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")