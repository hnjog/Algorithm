import sys
inp = sys.stdin.readline

num = int(inp().strip())

val = [0 for _ in range(num+1)]
dp = [0 for _ in range(num+1)]

for i in range(1,num+1):
    val[i] = int(inp().strip())

dp[1] = val[1]

for i in range(2,num+1):
    dp[i] = max(dp[i-3] + val[i-1],dp[i-2]) + val[i]
    dp[i] = max(dp[i],dp[i-1])

print(dp[num])