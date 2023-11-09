import sys

sys.setrecursionlimit(10**8)

inp = sys.stdin.readline

num = int(inp().strip())

graphs = [list(map(int,inp().split())) for _ in range(num)]

answer = [0 for _ in range(3)] # -1, 0, 1 갯수

def dq(startX,startY,length):
    if (startX < 0 or startX >= num or
        startY <0 or startY >= num):
        return
    
    startSymbol = graphs[startX][startY]

    sameSymbol = True
    for i in range(startX,startX + length):
        for j in range(startY,startY + length):
            if graphs[i][j] != startSymbol:
                sameSymbol = False
                break
        if sameSymbol == False:
            break
    
    if sameSymbol == True:
        answer[startSymbol + 1] +=1 # 어차피 -1,0,1 이므로 그냥 +1 해준 인덱스에 더해주면 된다
    else:
        nextLength = int(length / 3)
        for i in range(3):
            for j in range(3):
                dq(startX + nextLength * i,startY + nextLength * j,nextLength)
    

dq(0,0,num)

for i in answer:
    print(i)