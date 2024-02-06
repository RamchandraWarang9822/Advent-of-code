import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <file_path>")
    sys.exit(1)  

file_path = sys.argv[1]

try:
    with open(file_path, 'r') as file:
        crates = []
        instructions = []
        flag = False

        for line in file:
            line = line.removesuffix('\n')

            # flag to detect if blank line is passed
            if not line.strip():
                flag = True

            ''' seperate all the lines before blank line 
                in crates and after the blank line in 
                instruction
            '''
            if flag:
                instructions.append(line)
            else:
                crates.append(line)
        
        # Get the index of the crates character
        str = crates[-1]
        index = [1 , 5 , 7]
        for i in range(0,len(str)):
            if str[i].isdigit():
                index.append(int(i))

        crates.pop() # Remove the numeric line
        dock = []
        for i in index:
            list = []
            for line in reversed(crates):
                if line[i] != ' ':
                    list.append(line[i])
            dock.append(list)

        for row in dock:
            print(row)
        
        # Store the instructions values only
        instructions.pop(0)
        for i in instructions:
            _, number, _, source, _, dest = i.split()
            number, source, dest = map(int, [number, source, dest])
            source, dest = source - 1, dest - 1
            for n in range(number):
                value = dock[source].pop()
                dock[dest].append(value)
            # print(number, source, dest)
        print("After changes")

        for row in dock:
            print(row)

        result = ''.join(row.pop() for row in dock)
        print(result)

except FileNotFoundError:
    print(f"Error: File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")

