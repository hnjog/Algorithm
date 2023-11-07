import sys
inp = sys.stdin.readline

num = int(inp().strip())

val = list(map(int,inp().split()))
dp1 = [1 for _ in range(num)]
dp2 = [1 for _ in range(num)]

# 앞으로 돌기
for i in range(num):
    for j in range(i):
        if val[i] > val[j]:
            dp1[i] = max(dp1[i],dp1[j] + 1)

# 뒤로 돌기
for i in range(num-1,-1,-1):
    for j in range(num-1,i-1,-1):
        if val[i] > val[j]:
            dp2[i] = max(dp2[i],dp2[j] + 1)

mv = 0

for i in range(num):
    mv = max(dp1[i] + dp2[i] -1,mv)

print(mv)