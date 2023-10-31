import sys
from collections import OrderedDict

inp = sys.stdin.readline

holeCount, useCount = map(int,inp().split())

seq = list(map(int,inp().split()))

tap = dict()
answer = 0

# 가장 마지막에 사용되는 전기 기구를 뽑는다
# 다만, 안 사용되면 그 전기 기구를 뽑는다

for i in range(useCount):
    elect = seq[i]
    if elect in tap: # 이미 꽃여 있음
        continue

    if len(tap) < holeCount: # 빈칸 있음
        tap[elect] = 1
        continue
    
    # 빈 곳 없어서 가장 나중에 사용하는 녀석을 뽑는다
    key = -1
    ind = 0

    for ele in tap:
        tempInd = -1
        for j in range(i+1,useCount):
            electJ = seq[j]
            if electJ == ele: # 뽑을 녀석이다
                if j > tempInd:
                    tempInd = j
                    break
        if tempInd == -1:
            key = ele
            break
        elif tempInd > ind:
            ind = tempInd
            key = ele
    
    if key != -1:
        tap.pop(key)
    else:
        tap.popitem()

    tap[elect] = 1

    answer += 1

print(answer)