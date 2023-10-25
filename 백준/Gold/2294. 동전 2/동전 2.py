import sys
from collections import deque
import math

inp = sys.stdin.readline

n,k = map(int,inp().split())

coin = [0 for i in range(n)]

for i in range(n):
    coin[i] = int(inp().strip())

coin = list(set(coin))    # 중복요소 제거
coin.sort()

dp = [0] + [math.inf] * k

for i in range(len(coin)):
    for j in range(k + 1):
        if j >= coin[i]:
            dp[j] = min(dp[j], dp[j - coin[i]] + 1)

if dp[k] == math.inf:
    print(-1)
else:
    print(dp[k])