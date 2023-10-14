a = []

for i in range(9):
    a.append(int(input()))

ind = 1
maxIn = 0
max = 0

for i in a:
    if(i > max):
        max = i
        maxIn = ind
    
    ind += 1

print(max)
print(maxIn)