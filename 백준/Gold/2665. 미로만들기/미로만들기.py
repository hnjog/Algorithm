import sys
import heapq

# BFS
# 이미 주어진 그래프에서
# 0,0 -> (n -1, n-1)로 갈때
# 만나는 0의 최소 개수 구하기
# (미로를 고치려고 생각하지 말고)
# 코드를 짤 때 고려해야 할점
# 그냥 노드에 여기까지 오면서 
# 밟은 0의 개수를 적는 방식이 좋을듯??
# 더 작은 값으로 바꿔주기

inp = sys.stdin.readline

nNum = int(inp().strip())
graph = []
for i in range(nNum):
    graph.append(list(map(int, inp().strip())))

def bfs(graph):
    minheap = []
    heapq.heappush(minheap,[0,0,0]) # cost, pos x , pos y

    closePos = set()

    while minheap:
        cost, posX, posY = heapq.heappop(minheap)

        if posX == nNum - 1 and posY == nNum - 1:
            print(cost)
            return

        for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]:
            newX = posX + dx
            newY = posY + dy

            if 0 <= newX < nNum and 0 <= newY < nNum and (newX,newY) not in closePos:
                closePos.add((newX,newY))
                if graph[newX][newY] == 0:
                    newCost = 1
                else:
                    newCost = 0
                
                heapq.heappush(minheap,[cost + newCost,newX,newY])

bfs(graph)