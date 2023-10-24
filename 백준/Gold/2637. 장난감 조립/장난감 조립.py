import sys
from collections import deque

inp = sys.stdin.readline

# '우선순위'가 필요하며
# 필요한 '기본 부품'이 완제품을 만들기 위해 '얼마나'필요한가 에 대한 것
# 위상정렬
# 서로를 필요로 하는 경우는 없음 (scc X)

# 약간 top-down 방식으로 해보려고 함
# 위에서 미리 필요 개수를 정한뒤
# 해당 재료에 '자식'들이 있다면 그 수치를 유지한채 
# answer의 배열에 더해줄 예정
# 자식이 없다면 '기초'재료

num = int(inp().strip())
needs = int(inp().strip())
graph = [[] for _ in range(num)] # 그래프
answer = [0 for _ in range(num)] # 필요한 재료 인덱스에 answer 넣어주려 한다

que = deque()

#필요한 재료 공급받기
for i in range(needs):
    tar, need, count = map(int,inp().split()) # 만들것, 필요한 것, 필요한 수
    graph[tar - 1].append([need - 1, count]) # 해당 필요 요소 집어넣기

basic = []

for i in range(len(graph)):
    if len(graph[i]) == 0:
        basic.append(i)

que.append([num - 1,1])

# 필요한 재료를 넣어주기
while que:
    tar, needCount = que.popleft()
    
    for need, needC in graph[tar]:
        if need in basic: # 필요한 재료가 기본재료다
            answer[need] += needC * needCount
        else:
            find = False
            for i in range(len(que)):
                if que[i][0] == need:
                    que[i][1] += needC * needCount
                    find = True
                    break

            if find == False:
                que.append([need, needC * needCount])
    

for i in range(num):
    if answer[i] != 0:
        print(f'{i + 1} {answer[i]}')