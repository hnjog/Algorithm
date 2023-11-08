import sys

inp = sys.stdin.readline

num = int(inp().strip())

vals = list(map(int,inp().split()))

vals.sort()

times = 0
sumTimes = 0

for i in range(num):
    times += vals[i]
    sumTimes += times

print(sumTimes)