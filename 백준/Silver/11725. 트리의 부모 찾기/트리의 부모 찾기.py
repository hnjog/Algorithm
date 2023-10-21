import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**8)

vNum = int(input().strip())
eNum = vNum - 1
child = [[] for _ in range(vNum)]
# visit : tree 이긴 한데... 넣을까?
visit = [False] * vNum

parent = [0] * eNum # 1번 은 루트이기에, 2번부터 저장해야 한다

for i in range(eNum):
    start, to = map(int,input().split())
    child[start - 1].append(to - 1)
    child[to - 1].append(start - 1)

# 부모 정해줌 dfs
def setParent(start,pNode):
    visit[start] = True
    # 루트인 경우는 -1 들어오도록
    if pNode != -1:
        parent[start - 1] = pNode
    
    for i in range(len(child[start])):
        if visit[child[start][i]] == False:
            setParent(child[start][i],start)

setParent(0,-1)

for i in parent:
    print(i + 1)
