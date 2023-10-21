import sys

sys.setrecursionlimit(10**8)

input = sys.stdin.readline

# 음... 1번 기준으로 dfs를 돌리고
# 그 카운트를 반환하는 방식은??

result = 0

vNum = int(input().strip())
eNum = int(input().strip())

visit =[False] * vNum
child =[[] for _ in range(vNum)]

for i in range(eNum):
    start, to = map(int,input().split())
    child[start - 1].append(to - 1)
    child[to - 1].append(start - 1)

def dfs(start):
    visit[start] = True

    for i in range(len(child[start])):
        if visit[child[start][i]] == False:
            dfs(child[start][i])
            global result
            result += 1

dfs(0)

print(result)

