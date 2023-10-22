import sys
import queue
import math

# Bfs
# 최소비용 구하기
# n개의 도시
# A도시에서 B도시까지 가는데 드는 버스 비용을 최소화 시키고 싶음
# A->B 까지의 최소비용을 출력하기
# 도시는 1~n까지 존재

# 일단 시작점 부터 돌면서
# 주변 노드의 거리를 바꿔준다

cityNum = int(sys.stdin.readline().strip())
busNum = int(sys.stdin.readline().strip())
buses = [[] for _ in range(cityNum)]

for i in range(busNum):
    start,to,cost = map(int,sys.stdin.readline().split())
    buses[start-1].append([to - 1,cost]) # buses[start] 에 목적지와 cost를 담아둔다

# 해당 도시의 버스들을 'cost'가 낮은 것 위주로 정렬하기
for i in buses:
    i.sort(key=lambda x : x[1])

start,to = map(int,sys.stdin.readline().split())
start -= 1
to -= 1

def bfs(start,to,buses):
    # 각 도시간의 거리 (시작점 기준)
    distance = [math.inf] * cityNum
    distance[start] = 0 # 시작점은 0으로

    que = queue.Queue()
    que.put(start)

    while not que.empty():
        city = que.get()

        for busInfo in buses[city]: # [0] : to , [1] : cost
            if distance[busInfo[0]] > distance[city] + busInfo[1]:
                distance[busInfo[0]] = distance[city] + busInfo[1]
                que.put(busInfo[0])

    return distance[to]

print(bfs(start,to,buses))