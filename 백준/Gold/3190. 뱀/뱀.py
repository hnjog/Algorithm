import sys

# 힌트 큐

# 일단 사과를 먹으면 '몸 길이'가 늘어남
# 결국 '머리'가 '몸'에 박거나 맵 밖으로 나가버리면 게임 끝
# '이동'시 해당 위치에 '몸', '맵 밖'인지 체크
# 이후 '사과 여부' 체크

from collections import deque

def game(board,snakeCommand : deque):
    lifeTime = 0
    snakeBody = deque()
    boardSize = len(board)

    snakeBody.append([0,0]) # 꼬리

    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]

    snakeDir = 0
    x,y = 0,0
    board[0][0] = 1

    while True:
        lifeTime+= 1

        # 뱀 움직이기
        x += dx[snakeDir]
        y += dy[snakeDir]

        #일정시간 되었는지 확인하고 꺼내줘서 방향 바꿈
        if snakeCommand:
            if lifeTime >= snakeCommand[0][0]:
                com = snakeCommand.popleft()[1]
                if com == 'L':
                    snakeDir -= 1
                else:
                    snakeDir += 1
                snakeDir %= 4

        # 게임 오버
        if x < 0 or y < 0 or x >= boardSize or y >=boardSize:
            break

        # 몸아 와라
        snakeBody.append([x,y])

        # 사과먹었다
        if board[x][y] == 2:
            board[x][y] = 1
        elif board[x][y] == 0: #빈 곳이다
            board[x][y] = 1
            tx,ty= snakeBody.popleft()
            board[tx][ty] = 0
        else:   # 내 몸과 부딪혔다
            break

    return lifeTime

if __name__ == "__main__":
    boardSize = int(sys.stdin.readline().strip())

    board = [[0]*boardSize for _ in range(boardSize)]

    appleCount = int(sys.stdin.readline().strip())
    for i in range(appleCount):
        x,y = map(int,sys.stdin.readline().split())
        board[x-1][y-1] = 2 # 사과
    
    snakeMoveCount = int(sys.stdin.readline().strip())
    snakeTimeNCommand = deque(maxlen=snakeMoveCount)
    for i in range(snakeMoveCount):
        snakeTime,snakeMoveDir = sys.stdin.readline().split()
        snakeTime = int(snakeTime)
        snakeTimeNCommand.append([snakeTime,snakeMoveDir])
    
    print(game(board,snakeTimeNCommand))
