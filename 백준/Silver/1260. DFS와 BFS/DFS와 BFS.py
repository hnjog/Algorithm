import sys
sys.setrecursionlimit(10**8)

import queue

input = sys.stdin.readline

vNum,eNum,startV = map(int, input().split())

startV -= 1 # 인덱스로 쓸거라 -1 해줌

visit = [False] * vNum  # index가 곧 정점 번호로 (-1)
child = [[] for _ in range(vNum)]     # 해당 하는 인덱스 정점의 연결된 녀석들 (*[[]] * vNum 이런식으로 선언하면 '빈 리스트'가 전부 같은 객체로 인식된다)

def dfs(start):
    visit[start] = True
    print(f'{start + 1} ',end='')

    for i in child[start]:
        if visit[i]:
            continue

        dfs(i)
        
que = queue.Queue()
def bfs(start):
    visit[start] = True
    for i in child[start]:
        que.put(i)

    print(f'{start + 1} ',end='')

    while que.empty() == False:
        g = que.get()
        if visit[g]:
            continue

        print(f'{g + 1} ',end='')
        visit[g] = True

        for i in child[g]:
            if visit[i]:
                continue
            que.put(i)

for i in range(eNum):
    startVert,toV = map(int,input().split())
    child[startVert-1].append(toV - 1) # 어차피 visit로 중복 체크 할거라 그냥 담음
    child[toV-1].append(startVert - 1) # 어차피 visit로 중복 체크 할거라 그냥 담음

for i in child:
    i.sort()

dfs(startV)
print()
visit = [False] * vNum
bfs(startV)
