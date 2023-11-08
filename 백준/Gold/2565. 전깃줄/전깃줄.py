import sys
inp = sys.stdin.readline

num = int(inp().strip())

values = [list(map(int,inp().split())) for i in range(num)]
dp = [1 for i in range(num)]

values.sort(key= lambda x : x[0])

for i in range(num):
    for j in range(i,-1,-1):
        if values[i][1] > values[j][1]:
            dp[i] = max(dp[i], dp[j] + 1)

print(num - max(dp))
