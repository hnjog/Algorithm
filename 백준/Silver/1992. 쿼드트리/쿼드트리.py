import sys

# 쿼드트리 문제
# 함수 들어갈때 (
# 나올때)

def quad(size,arr,x,y,originSize):
    if x < 0 or y < 0 or x > originSize or y > originSize:
        return
    
    num = arr[x][y]

    isSame = True
    for i in range(x,x + size):
        for j in range(y,y + size):
            if arr[i][j] != num:
                isSame = False
                break
        if isSame == False:
            break

    if isSame == True:
        print(num,end='')
    else:
        print("(", end ='')
        halfSize = size // 2
        quad(halfSize,arr,x,y,originSize)
        quad(halfSize,arr,x,y+halfSize,originSize)
        quad(halfSize,arr,x+halfSize,y,originSize)
        quad(halfSize,arr,x+halfSize,y+halfSize,originSize)
        print(')',end='')

if __name__ == "__main__":
    num = int(sys.stdin.readline().strip())

    board = [[None] * num for _ in range(num)]

    for i in range(num):
        arr = sys.stdin.readline()
        for j in range(num):
            board[i][j] = int(arr[j])


    quad(num,board,0,0,num)