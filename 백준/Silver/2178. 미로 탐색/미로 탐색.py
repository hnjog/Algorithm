import sys

import queue

boardY,boardX = map(int,sys.stdin.readline().split())
board = []

for i in range(boardY):
    board.append(list(map(int,sys.stdin.readline().rstrip())))

def bfs(bX,bY):
    que = queue.Queue()
    que.put([0,0])

    dx = [1,0,-1,0]
    dy = [0,1,0,-1]

    while not que.empty():
        posY,posX = que.get()
        
        for i in range(4):
            nx = posX + dx[i]
            ny = posY + dy[i]

            if 0 <= nx <boardX and 0 <= ny < boardY and board[ny][nx] == 1:
                board[ny][nx] = board[posY][posX] + 1
                que.put([ny,nx])
        
    return board[bY-1][bX-1]

print(bfs(boardX,boardY))
