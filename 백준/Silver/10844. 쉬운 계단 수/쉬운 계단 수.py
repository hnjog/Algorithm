import sys
import math

inp = sys.stdin.readline

n = int(inp().strip())

dp = [[0 for _ in range(10)]for _ in range(n)]

for i in range(1,10):
    dp[0][i] = 1

MOD = 1000000000

def dfs():
    sum = 0
    for process in range(1,n):
        for i in range(0,10):
            if i == 0:
                dp[process][i] = dp[process - 1][i+1]
            elif i == 9:
                dp[process][i] = dp[process - 1][i-1]
            else:
                dp[process][i] = dp[process - 1][i-1] + dp[process - 1][i+1]

    for i in range(0,10):
        sum += dp[n-1][i]

    return sum

print(dfs()%MOD)