import sys
import heapq
from collections import deque

inp = sys.stdin.readline

n,m = map(int,inp().split())
maps = [list(map(int,inp().split())) for _ in range(n)]

s, x, y = map(int,inp().split())

visit = [[False for i in range(n)] for j in range(n)]
virusList = []
heapq.heapify(virusList)

for i in range(n):
    for j in range(n):
        if maps[i][j] != 0:
            heapq.heappush(virusList,(maps[i][j],i,j))

# 우선순위가 아니라
# 맨처음만 queue를 정렬하여 집어넣은 후에는,
# 이후는 계속 BFS로 처리가 가능할듯 싶음

time = 0
while virusList:
    if time >= s:
        break

    time += 1

    que = deque()

    for i in range(len(virusList)):
        que.append(heapq.heappop(virusList)) # 현재 시점에서의 우선순위 큐 저장
    
    while que:
        vType, vy,vx = que.popleft()

        for dy,dx in [(-1,0),(1,0),(0,-1),(0,1)]:
            ny = vy + dy
            nx = vx + dx
            if 0 <= ny < n and 0 <= nx < n and maps[ny][nx] == 0:
                maps[ny][nx] = vType
                heapq.heappush(virusList,(vType,ny,nx))

print(maps[x-1][y-1])
