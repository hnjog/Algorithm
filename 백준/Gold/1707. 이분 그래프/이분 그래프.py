import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**8)

# 힌트 DFS
# 음... 노드마다 색깔을 주고
# '인접'한 경우 색을 바꾸어 주기
# 이후, 모든 노드 순회 후
# 재탐색 시, 같은 색끼리 인접하였는지를 확인하기


def dfs(start,child,color,switchAnother=False):
    if switchAnother:
        color[start] = 1
    else:
        color[start] = 2
    
    for i in range(len(child[start])):
        if color[child[start][i]] == color[start]:
            return False
        
        if color[child[start][i]] != 0:
            continue
        
        if not dfs(child[start][i],child,color,not switchAnother):
            return False
        
    return True

testNum = int(input().strip())
# 사실상 메인 반복문
resultStr = []

for i in range(testNum):
    vNum, eNum = map(int,input().split())
    child = [[] for _ in range(vNum)]
    color = [0] * vNum  # 1이라면 2, 2이라면 1을 (0 : 방문 안함)

    for j in range(eNum):
        start, to = map(int,input().split())
        child[start -1].append(to - 1)
        child[to - 1].append(start - 1)

    for i in range(vNum):
        if color[i] == 0:
            result = dfs(i,child,color)
            if result == False:
                break


    if result == False:
        resultStr.append("NO")
    else:
        resultStr.append("YES")

for i in resultStr:
    print(i)