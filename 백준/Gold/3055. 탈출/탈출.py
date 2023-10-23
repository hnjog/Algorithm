import sys
from collections import deque

inp = sys.stdin.readline

# 아마 BFS?
# 고슴도치 탈출
# 지도에 아무것도 없다면 .
# 비버의 굴 : D (목적지)
# 고슴도치 시작점 : S(시작점)
# 물이 차오른 곳 : *
# 돌 : X

# 특징
# 물은 상하좌우 중, 비어있는 곳을 침범
# 고슴도치는 상하좌우 이동 가능
# 물과 고슴도치는 '돌'로 이동할 수 없다
# 고슴도치는 물이 찬 곳 , 물이 차오를 곳 으로 이동할 수 없음
# 만약 고슴도치가 탈출할 수 없다면 KAKTUS 출력

row, column = map(int,inp().split())
Graph = [list(inp().strip()) for _ in range(row)]

# 물과 고슴도치를 각각 BFS 따로 돌리기

def bfs():
    objque = deque()
    hegiVisit = [[0] * column for _ in range(row)]

    # 물 먼저 넣어주기
    for i in range(row):
        for j in range(column):
            if Graph[i][j] == '*':
                objque.appendleft(['w',i,j])
            elif Graph[i][j] == 'S':
                objque.append(['h',i,j])

    dx = [-1,1,0,0]
    dy = [0,0,-1,1]

    while objque:
        obj,px,py = objque.popleft()

        for i in range(4):
            nx = px + dx[i]
            ny = py + dy[i]
            if 0 <= nx < row and 0 <= ny < column:
                if obj == 'w': # 물인 경우
                    if Graph[nx][ny] == '.':
                        objque.append(['w',nx,ny])
                        Graph[nx][ny] = '*'
                else: # 고슴도치인 경우
                    if Graph[nx][ny] == 'D':
                        return hegiVisit[px][py] + 1
                    if Graph[nx][ny] == '.' and hegiVisit[nx][ny] == 0:
                        hegiVisit[nx][ny] = hegiVisit[px][py] + 1
                        objque.append(['h',nx,ny])

    return -1

result = bfs()

if result == -1:
    print('KAKTUS')
else:
    print(result)
