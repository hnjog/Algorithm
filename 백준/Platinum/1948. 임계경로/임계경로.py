import sys
from collections import deque
inp = sys.stdin.readline
sys.setrecursionlimit(10**8)

n = int(inp().strip())
m = int(inp().strip())

cities = [[] for _ in range(n)]
reverCity = [[] for _ in range(n)]
inDegree = [0 for _ in range(n)]

for i in range(m):
    st, t, cost = map(int,inp().split())
    cities[st-1].append([t-1,cost])
    reverCity[t-1].append([st-1,cost])
    inDegree[t-1] += 1

start,to = map(int,inp().split())
 
que = deque()

for i in range(n):
    if inDegree[i] == 0:
        que.append(i)
        
answer = [[0,[]] for _ in range(n)]

while que:
    cityIndex = que.popleft()

    for targetCity, targetCost in cities[cityIndex]:
        if answer[targetCity][0] < answer[cityIndex][0] + targetCost:
            answer[targetCity][0] = answer[cityIndex][0] + targetCost
            answer[targetCity][1] = [cityIndex]
        elif answer[targetCity][0] == answer[cityIndex][0] + targetCost:
            answer[targetCity][1].append(cityIndex)
 
        inDegree[targetCity] -= 1
        if inDegree[targetCity] == 0:
            que.append(targetCity)

bQ = deque([to-1])
route = set()

while bQ:
    curr = bQ.popleft()
    for i in answer[curr][1]:
        if (curr,i) not in route:
            route.add((curr,i))
            bQ.append(i)

print(answer[to-1][0])
print(len(route))