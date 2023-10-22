import sys
import queue
import math

# 단방향 간선으로 주어진다고 명시함

nNum,eNum,distanceK,start = map(int,sys.stdin.readline().split())
#인접 리스트
edge = [[] for _ in range(nNum)]

for i in range(eNum):
    st,to = (map(int,sys.stdin.readline().split()))
    edge[st-1].append(to-1)

def Bfs(start,edge,distance):
    que = queue.Queue()
    que.put(start)              # 시작지점 넣어준다
    result = []
    visit = [False] * len(edge) # 
    distance[start] = 0
    
    while not que.empty():
        node = que.get()

        if distance[node] == distanceK: # 현재 노드의 거리가 목표거리와 같다면
            result.append(node)
        elif distance[node] < distanceK: # 현재 노드의 거리가 목표거리보다 작다면
            for neigbor in edge[node]:
                if not visit[neigbor] and distance[neigbor] > distance[node]:
                    distance[neigbor] = distance[node] + 1 # 이전 노드보다 + 1
                    que.put(neigbor)
                    visit[neigbor] = True
        # 현재 노드의 거리가 목표 거리를 넘어서는 경우는 계산 필요 없음

    return result

# 가중치 초기화
init_dis = [math.inf] * nNum
resultAr = Bfs(start - 1, edge,init_dis)

if resultAr:
    resultAr.sort()
    for i in resultAr:
        print(i + 1)
else:
    print(-1)
