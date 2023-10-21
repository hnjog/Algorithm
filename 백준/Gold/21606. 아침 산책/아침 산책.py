import sys

# 산책 경로에 그 외의 '실내' 장소는 없어야 함
# 서로 다른 산책 경로의 개수

# start가 inOut[start]의 '실내'인 경우에만 되도록 밖에서 넣어줘야 함
def dfs(start,inOut,child):
    visit = set()
    stack = [start]

    res = 0
    while stack:
        node = stack.pop()
        visit.add(node)

        for neighbor in child[node]:
            if neighbor not in visit:
                if inOut[neighbor] == '1':
                    res += 1
                else:
                    stack.append(neighbor)

    return res

vNum = int(sys.stdin.readline().strip()) # 정점의 개수
eNum = vNum - 1
inOut = sys.stdin.readline().strip()     # 각 정점의 실내/실외 정보 (1 : 실내, 0 : 실외)

child = [[] for _ in range(vNum)]
for i in range(eNum):
    start,to = map(int,sys.stdin.readline().split())
    child[start-1].append(to-1)
    child[to-1].append(start-1)

result = 0

for i in range(vNum):
    if inOut[i] == '1':
        result += dfs(i,inOut,child)

print(result)
