import sys
from collections import deque
sys.setrecursionlimit(10**8)

inp = sys.stdin.readline

boardX, boardY = map(int, inp().split())
board = [list(map(int, inp().split())) for _ in range(boardX)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# DFS로 빙하 녹이는 함수
def meltIceberg(startX, startY, visit):
    nearZeroCount = 0

    for i in range(4):
        nx, ny = startX + dx[i], startY + dy[i]
        if 0 <= nx < boardX and 0 <= ny < boardY and not visit[nx][ny]:
            if board[nx][ny] == 0:
                nearZeroCount += 1
            else:
                visit[nx][ny] = True
                meltIceberg(nx, ny, visit)

    board[startX][startY] = max(0, board[startX][startY] - nearZeroCount)

# '빙하 덩어리' 확인 함수
def checkIceberg():
    visit = [[False] * boardY for _ in range(boardX)]
    count = 0

    for i in range(boardX):
        for j in range(boardY):
            if board[i][j] != 0 and not visit[i][j]:
                count += 1
                visit[i][j] = True
                meltIceberg(i, j, visit)

    return count

time = 0
while True:
    remaining_icebergs = checkIceberg()

    if remaining_icebergs == 0:
        print(0)
        break

    if remaining_icebergs >= 2:
        print(time)
        break

    time += 1
