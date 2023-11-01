import sys
import math
sys.setrecursionlimit(10**8)

inp = sys.stdin.readline

num,dNum = map(int,inp().split())

dList = []

for i in range(dNum):
    dList.append(int(inp().strip()))

# 한 번에 뛸수 있는 최대 거리는
# sqrt() num * 2 ) + 1
max_speed = int((2*num) **0.5) + 1
dp = [[math.inf for _ in range(max_speed + 1)] for _ in range(num+1)]

# 시작점 초기화
dp[1][0] = 0

for step in range(2,num+1):
    if step in dList:
        continue

    for speed in range(1,max_speed):
        dp[step][speed] = min(dp[step-speed][speed - 1],
                              dp[step-speed][speed],
                              dp[step-speed][speed + 1]) + 1

result = min(dp[num])

if result == math.inf:
    print(-1)
else:
    print(result)
