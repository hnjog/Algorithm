import sys
from collections import deque

inp = sys.stdin.readline

n = int(inp().strip())
buildings = [[] for _ in range(n)]
inDegree = [0 for _ in range(n)]

buildTime = [0 for _ in range(n)]
child = [[] for _ in range(n)]
answer = [0 for _ in range(n)]

for i in range(n):
    buildings[i] = list(map(int,inp().split()))
    buildTime[i] = buildings[i][0]
    answer[i] = buildTime[i] # 적어도 자기 짓는 시간은 필요함
    for j in range(1,len(buildings[i]) - 1):
        inDegree[i] += 1
        child[buildings[i][j] - 1].append(i)

que = deque()



for i in range(n):
    if inDegree[i] == 0:
        que.append(i)

while que:
    build = que.popleft()

    for i in child[build]:
        inDegree[i] -= 1
        # 기존에 있던 값과
        # 현재값 + 이거 짓는데 필요한 값을 넣어준다
        answer[i] = max(answer[i],answer[build] + buildTime[i])
        if inDegree[i] == 0:
            que.append(i)

for a in answer:
    print(a)
    