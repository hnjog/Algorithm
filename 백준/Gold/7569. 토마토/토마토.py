import sys
from collections import deque

inp = sys.stdin.readline

# BFS?
# 3차원 배열??
# 익은 토마토는 
# 근처의 익지 않은 토마토에 영향을 줌 (상하는거 아닌가?)
# 인접한 기준은 '상,하,좌,우,전,후' 한칸씩
# 대각선은 영향 x
# 3차원 길찾기 BFS
# visit 를 잘 설정하면 가능할듯한데
# 1이 적힌 녀석들 근처(6방향)에 0이 있다면 1로 바꿔준다

# 가로,세로,높이
m,n,h = map(int,inp().split())
tomatos = [[[0 for k in range(m)] for i in range(n)] for j in range(h)]
visit = [[[False for k in range(m)] for i in range(n)]for j in range(h)]
queue = deque()
endCondition = True

for i in range(h):
    for j in range(n):
        tomatos[i][j] = list(map(int,inp().split()))
        for k in range(m):
            if tomatos[i][j][k] == 1:
                visit[i][j][k] = True
                queue.append((i,j,k,0))
            elif tomatos[i][j][k] == 0:
                endCondition = False

def bfs(tomatos):
    count = 0
    
    while queue:
        py,px,pz,day = queue.popleft()

        if all(tomatos[y][x][z] != 0 for y in range(h) for x in range(n) for z in range(m)):
            # 여기서 pop 다하면서
            # 내부에서 day 높은 값으로 바꿔주기
            tempDay = day
            while queue:
                tempDay = max(tempDay,queue.popleft()[3])
            count = tempDay
            break

        for dy, dx, dz in [(-1,0,0),(1,0,0),(0,-1,0),(0,1,0),(0,0,-1),(0,0,1)]:
            ny,nx,nz = py + dy,px+dx,pz+dz
            if 0 <= ny < h and 0 <= nx < n and 0 <= nz < m:
                if tomatos[ny][nx][nz] == -1:
                    continue

                if visit[ny][nx][nz] == False:
                    visit[ny][nx][nz] = True
                    tomatos[ny][nx][nz] = 1
                    queue.append((ny,nx,nz,day+1))

    if count == 0:
        return -1
    
    return count


if endCondition == True:
    print(0)
else:
    print(bfs(tomatos))