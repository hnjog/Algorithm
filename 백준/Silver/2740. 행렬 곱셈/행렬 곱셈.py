import sys

inp = sys.stdin.readline

n,m = map(int,inp().split())
aMatrix = [list(map(int,inp().split())) for _ in range(n)]
m,k = map(int,inp().split())
bMatrix = [list(map(int,inp().split())) for _ in range(m)]

transBM = []

for i in range(k):
    transBM.append([])
    for j in range(m):
        transBM[i].append(bMatrix[j][i])

result = []
for i in range(n):
    result.append([])
    for j in range(k):
        temp = 0
        for l in range(m):
            temp += aMatrix[i][l] * transBM[j][l]
        result[i].append(temp)

for i in range(n):
    print(*result[i])
