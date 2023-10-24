import sys
inp = sys.stdin.readline

sys.setrecursionlimit(10**8)

# 줄 세우기
# 위상정렬
# 학생수, 키 비교한 횟수
# A B (A 가 B에 와야함)

# A가 B의 부모라면 가능하다
# 서로 관계가 없다면 그냥 for문 돌면서
# 음... 부모를 여러 개 받는 방식으로
# 개념은 이상하지만 그냥 parent라 하고
# '연결된' 노드 부터 출력해주는 방식을 고려하기

nNum,eNum = map(int,inp().split())

parent = [[] for i in range(nNum)]
printed = [False for i in range(nNum)]

for i in range(eNum):
    st,to = map(int,inp().split())
    parent[to-1].append(st-1)# 자기 부모 담아줌

def printParents(startNode):
    # 각 정점을 돌면서
    # '부모'가 있는지 확인
    # 부모 존재시 '그 부모'의 부모 확인
    # 또한 이미 '출력했는지'도 확인 필요
    if printed[startNode] == True:
        return
    
    if len(parent[startNode]) == 0:
        print(f'{startNode + 1} ',end='')
        printed[startNode] = True
        return
    
    for i in parent[startNode]:
        printParents(i)
    
    print(f'{startNode + 1} ',end='')
    printed[startNode] = True

for i in range(nNum):
    printParents(i)