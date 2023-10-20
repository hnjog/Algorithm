import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**8)

result = 0

V,E = map(int,input().split())

G = []
for i in range(E):
    edgeData = list(map(int,input().split()))
    edgeData[0],edgeData[1],edgeData[2] = edgeData[2],edgeData[0],edgeData[1]
    if edgeData[1] > edgeData[2]:
        edgeData[1],edgeData[2] = edgeData[2],edgeData[1]
    G.append(edgeData)

G.sort()

# 각 노드의 부모를 저장할 배열
parent = [i for i in range(V)]

def getParent(node : int)->int: # union-find
    if parent[node] == node:
        return node
    
    parent[node] = getParent(parent[node])

    return parent[node]

def unionParent(a : int, b : int):
    aP = getParent(a)
    bP = getParent(b)
    if aP < bP :
        parent[bP] = aP
    else:
        parent[aP] = bP

def findParent(a:int,b:int)->bool:
    aP = getParent(a)
    bP = getParent(b)
    if aP == bP:
        return True
    else:
        return False


for i in G:
    if findParent(i[1]-1,i[2]-1) == False:
        unionParent(i[1]-1,i[2]-1)
        result += i[0]

print(result)