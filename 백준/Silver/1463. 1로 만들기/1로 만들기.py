import sys
import math

inp = sys.stdin.readline

n = int(inp().strip())

dp = [0] + [math.inf for _ in range(n)]

dp[0] = 0
dp[1] = 0

def process(x:int):
    for i in range(2,x+1):
        v2 = v3 = math.inf
        if i % 3 == 0:
            v3 = dp[i//3]
        if i% 2 == 0:
            v2 = dp[i//2]
        
        dp[i] = min(v2 + 1,v3 + 1,dp[i-1] + 1)

    return dp[x]

print(process(n))