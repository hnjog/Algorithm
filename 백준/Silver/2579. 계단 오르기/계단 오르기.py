import sys

inp = sys.stdin.readline

n = int(inp().strip())

dp = [0 for _ in range(n + 1)]
val = [0 for _ in range(n+1)]

for i in range(1,n+1):
    val[i] = int(inp().strip())

for i in range(1,n+1):
    dp[i] = max(dp[i-3] +val[i-1] ,dp[i-2]) + val[i]

print(dp[n])
