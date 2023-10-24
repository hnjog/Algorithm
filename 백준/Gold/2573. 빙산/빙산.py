from collections import deque
import sys
input = sys.stdin.readline

dy = [-1,1,0,0]
dx = [0,0,-1,1]

def bfs(startY,startX,visit):
    queue = deque()
    queue.append([startY,startX])
    visit[startY][startX] = True

    while queue:
        y,x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if (0<=ny<n) and (0<=nx<m):
                if graph[ny][nx] == 0:
                    visit[y][x] += 1

                if visit[ny][nx] == False and graph[ny][nx] != 0:
                    queue.append([ny,nx])
                    visit[ny][nx] = True


n , m = map(int,input().split())
graph = [list(map(int,input().split())) for _ in range(n)]


#두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램
time = 0
while True:
    count = 0
    visited = [[0] * m for _ in range(n)]

    # bfs 돌며 근처에 0 확인 및
    # 얼음이 두 덩어리인지 확인
    for i in range(n):
        for j in range(m):
            # 0이 아니고, 방문 안했다
            if not visited[i][j] and graph[i][j] !=0:
                bfs(i,j,visited) #bfs로 탐색하기
                count +=1

    # 그래프에서 얼음 녹은만큼 빼주기
    for i in range(n):
        for j in range(m):
            if visited[i][j]:
                graph[i][j] = max(graph[i][j] - visited[i][j] + 1,0)

    time += 1
    if count == 0:
        print(0)
        exit()
    if count >=2 :
        break

print(time-1)