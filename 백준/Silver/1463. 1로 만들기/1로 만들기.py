import sys
import math

sys.setrecursionlimit(10**8)

inp = sys.stdin.readline

n = int(inp().strip())

dp = [0] + [math.inf for _ in range(n)]

dp[1] = 0

def process(x : int)->int:
    if x <= 1:
        return 0
    
    if dp[x] != math.inf:
        return dp[x]

    sum = math.inf

    if x % 3 == 0 and x % 2 == 0:
        sum = min(process(x//3) + 1,process(x//2) + 1)
    elif x % 3 == 0:
        sum = min(process(x//3) + 1,process(x - 1) + 1)
    elif x % 2 == 0:
        sum = min(process(x - 1) + 1,process(x//2) + 1)
    else:
        sum = process(x - 1) + 1
    
    dp[x] = min(sum,dp[x])

    return dp[x]

print(process(n))