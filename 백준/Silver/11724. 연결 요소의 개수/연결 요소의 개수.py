import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**8)

vNum,eNum = map(int,input().split())

# scc 구하는 게 뭐가 있었지??
# 타잔?
# id 로 초기화후, 연결되어 있으면, 해당 id값으로 덮어씌우기

# 이러한 방식은 '노드'의 'key'와 'value'를 같이 처리하는 방식


idArr = [i for i in range(vNum)] # 먼저 각 id를 초기화(인덱스이기에 -1)

def check(node:int)->int:
    if idArr[node] == node:
        return node
    
    idArr[node] = check(idArr[node])

    return idArr[node]

def union(a,b):
    aid = check(a)
    bid = check(b)
    temp = 0
    if aid < bid:
        temp = idArr[bid]
        for i in range(len(idArr)):
            if idArr[i] == temp:
                idArr[i] = aid
    else:
        temp = idArr[aid]
        for i in range(len(idArr)):
            if idArr[i] == temp:
                idArr[i] = bid

# 이미 check를 통하여 
# '부모'를 바꿔준 경우에 대하여
# 해당 녀석을 '부모'로 삼았던 녀석들 전부를
# 추가적으로 부모를 바꾸어주어야 한다
G = []

for i in range(eNum):
    G.append(list(map(int,input().split())))

G.sort()


for i in G:
    st = check(i[0] - 1)
    to = check(i[1] - 1)
    if st != to:
        union(i[0] - 1,i[1] - 1)

groups = set()

for i in idArr:
    groups.add(i)

print(len(groups))
