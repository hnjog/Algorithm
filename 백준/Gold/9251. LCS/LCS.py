import sys

inp = sys.stdin.readline

MAX_INPUT_V = 1001

cTable = [[0 for i in range(MAX_INPUT_V)] for i in range(MAX_INPUT_V)]

a = inp().strip()
b = inp().strip()

# i,j 가 0인 경우는 cTable[i,j] = 0
# a[i] == b[j] 인 경우, cTable[i][j] = cTable[i-1][j-1] + 1
# a[i] != b[j] 인 경우, cTable[i][j] = max(cTable[i-1][j],cTable[i][j-1])

def checkLcsCount(a,b,cTable)->int:
    aSize = len(a)
    bSize = len(b)

    if aSize == 0 or bSize == 0:
        return 0

    # 이미 i,j 가 0인 경우에 대해선
    # '초기값'이 0이기에 스킵    
    # 1부터 Size까지 비교
    # 다만 문자열 자체는 0~Size-1 까지 비교해야 하므로
    # (테이블의 각 0번째는 비워둔다)
    for i in range(1,aSize+1):
        for j in range(1,bSize+1):
            if a[i-1] == b[j-1]:
                cTable[i][j] = cTable[i-1][j-1] + 1
            else:
                cTable[i][j] = max(cTable[i-1][j],cTable[i][j-1])
    
    return cTable[aSize][bSize]


print(checkLcsCount(a,b,cTable))