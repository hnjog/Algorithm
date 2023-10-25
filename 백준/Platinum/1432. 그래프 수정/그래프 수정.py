import sys
import heapq

inp = sys.stdin.readline

n = int(inp().strip())
graph = [[] for _ in range(n)]
outDegree = [0 for _ in range(n)]
answer = [0 for i in range(n)]
child = [[] for _ in range(n)]

# 인접행렬을 입력 받는다
for i in range(n):
    graph[i] = list(*inp().split())
    # 인접리스트로 변환
    for j in range(len(graph[i])):
        if graph[i][j] == '1':
            child[j].append(i)  # 진출 차수로 구하기에 역으로 향하는 녀석에게 넣어준다
            outDegree[i] += 1   # 진출 차수가 있다면 +1을 해준다

def topology_sort(num):
    # heapq 사용 이유
    # 답을 여러 개 구했을때, 가장 오름차순으로 출력하기 위함
    # 최대 힙으로 사용
    heap = []

    for i in range(n):
        if outDegree[i] == 0:
            heapq.heappush(heap,-i) # 최대 힙
    
    while heap:
        # 인덱스 가장 큰 노드를 꺼냄
        # 해당 노드와 연결된 노드들의 진출차수를 빼줌
        curr = -heapq.heappop(heap)
        answer[curr] = num # 큐에서 빼낸 녀석에 가장 큰 숫자(n)을 넣어준다

        for node in child[curr]:
            outDegree[node] -=1 # 진출 차수 빼줌
            if outDegree[node] == 0: # 새로 진출차수 0인 녀석이면 넣어준다
                heapq.heappush(heap,-node)
        
        num -= 1

topology_sort(n)

if answer.count(0) > 2:
    print(-1)
else:
    print(*answer)
