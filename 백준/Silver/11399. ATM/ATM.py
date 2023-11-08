import sys

inp = sys.stdin.readline

num = int(inp().strip())

vals = list(map(int,inp().split()))

vals.sort()

times = [0 for _ in range(num)]
sumTimes = 0

for i in range(num):
    times[i] = times[i-1] + vals[i]
    sumTimes += times[i]

print(sumTimes)