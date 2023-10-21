import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**8)

# DFS
# 다만 아까처럼 Color 를 이용 (이분 그래프)
# 시작과 도착점 모두 '실내' 여야 함
# 산책 경로에 그 외의 '실내' 장소는 없어야 함
# 서로 다른 산책 경로의 개수

# 일단 중간에 '실외'가 반드시 들어갈 필요는 없음

vNum = int(input().strip()) # 정점의 개수
eNum = vNum - 1
inOut = input().strip()     # 각 정점의 실내/실외 정보 (1 : 실내, 0 : 실외)

visit = [False] * vNum
child = [[] for _ in range(vNum)]
for i in range(eNum):
    start,to = map(int,input().split())
    child[start-1].append(to-1)
    child[to-1].append(start-1)

result = 0

# start가 inOut[start]의 '실내'인 경우에만 되도록 밖에서 넣어줘야 함
def dfs(start):
    visit[start] = True

    for i in range(len(child[start])):
        if visit[child[start][i]] == True:
            continue

        if inOut[child[start][i]] == '1':
            global result
            result += 1
            continue

        dfs(child[start][i])

for i in range(vNum):
    if inOut[i] == '1':
        visit = [False] * vNum
        dfs(i)

print(result)
