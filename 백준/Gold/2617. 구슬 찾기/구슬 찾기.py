import sys
from collections import deque
sys.setrecursionlimit(10**8)

inp = sys.stdin.readline

n, m = map(int,inp().split())
hevParent = [[] for _ in range(n)]
ligChild = [[] for _ in range(n)]
for i in range(m):
    heavy, light = map(int,inp().split())
    hevParent[light-1].append(heavy - 1)
    ligChild[heavy-1].append(light - 1)

for i in range(n):
    hevParent[i] = set(hevParent[i])
    ligChild[i] = set(ligChild[i])

def dfs(start)->bool:
    hCount = [0]
    lCount = [0]

    stack = [(start,-1)]
    hvisit = [False for _ in range(n)]
    lvisit = [False for _ in range(n)]

    while stack:
        currNode, fMode = stack.pop()
        if fMode == -1:
            if check(stack,currNode,hevParent,hCount,hvisit,1) == True:
                return True
            if check(stack,currNode,ligChild,lCount,lvisit,0) == True:
                return True
        elif fMode == 1:
            if check(stack,currNode,hevParent,hCount,hvisit,fMode) == True:
                return True
        else:
            if check(stack,currNode,ligChild,lCount,lvisit,fMode) == True:
                return True

    return False

def check(stack : list,currNode,compares, Count,visit,check)->bool:
    visit[currNode] = True
    for i in compares[currNode]:
        if visit[i] == False:
            visit[i] = True
            Count[0] += 1
            if Count[0] >= n/2:
                return True
            stack.append((i,check))
    return False


answer = 0
for i in range(n):
    if dfs(i):
        answer+=1

print(answer)
