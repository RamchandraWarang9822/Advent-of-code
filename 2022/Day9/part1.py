# import sys

# if len(sys.argv) != 2:
#     print("Usage: python script.py <file_path>")
#     sys.exit(1)  

# file_path = sys.argv[1]
file_path = "input.txt"

visited = set()
x ,y = 0, 0
tailX, tailY = 0, 0

# def updateRope(direction, x, y, tailX, tailY):
#   if direction == 'U':
#     y += 1
#   elif direction == 'D':
#     y -= 1
#   elif direction == 'L':
#     x -= 1
#   elif direction == 'R':
#     x += 1

#   if x - tailX >= 2 and y - tailY >= 1 or x - tailX >= 1 and y - tailY >= 2:
#     tailX += 1
#     tailY += 1
#   elif x - tailX <= -2 and y - tailY <= -1 or x - tailX <= -1 and y - tailY <= -2:
#     tailX -= 1
#     tailY -= 1
#   elif x - tailX >= 2 and y - tailY <= -1 or x - tailX >= 1 and y - tailY <= -2:
#     tailX += 1
#     tailY -= 1
#   elif x - tailX <= -1 and y - tailY >= 2 or x - tailX <= -2 and y - tailY >= 1:
#     tailX -= 1
#     tailY += 1
#   elif y - tailY >= 2:
#     tailY += 1
#   elif y -tailY <= -2:
#     tailY -= 1
#   elif x - tailX >= 2:
#     tailX += 1
#   elif x - tailX <= -2:
#     tailX -= 1


try:
  with open(file_path, 'r') as file:
    for line in file:
      line = line.strip()
      direction, steps = line.split()
      print(direction, steps)
      

      visited.add((0,0))
      for i in range(int(steps)):
        if direction == 'U':
          y += 1
        elif direction == 'D':
          y -= 1
        elif direction == 'L':
          x -= 1
        elif direction == 'R':
          x += 1

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

        print(tailX, tailY)
        visited.add((tailX, tailY))

    # for i in visited:
    #   print(i)

    print(len(visited))

except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")