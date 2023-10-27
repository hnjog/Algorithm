import sys

inp = sys.stdin.readline

# 0/1 배낭 문제
# bottom - up (tabulation)

num, weight = map(int,inp().split())

valueArr = [0 for _ in range(num)]
weightArr = [0 for _ in range(num)]

vTable = [[0 for _ in range(weight + 1)] for _ in range(num + 1)]

for i in range(num):
    w,v = map(int,inp().split())
    weightArr[i] = w
    valueArr[i] = v


def calcValue(vArr,wArr,vTable):
    for i in range(1,num+1):
        for j in range(1,weight + 1):
            if j >= wArr[i-1]:
                vTable[i][j] = max(vTable[i-1][j - wArr[i-1]] + vArr[i-1],vTable[i-1][j])
            else:
                vTable[i][j] = vTable[i-1][j]

    return vTable[num][weight]

print(calcValue(valueArr,weightArr,vTable))
