import sys
from collections import deque

inp = sys.stdin.readline

num = int(inp().strip())

times = [list(map(int,inp().split())) for _ in range(num)]
times.sort(key= lambda x : (x[1],x[0]))

answer = 0
mainTime = 0
index = 0
isUseMeetingRoom = False

while index < num:
    if isUseMeetingRoom == False: # 회의실 미사용 중이면 사용하고 인덱스, 정답 증가
        isUseMeetingRoom = True
        mainTime = times[index][1] # 바로 끝나는 시간으로
        answer+=1
        index += 1
        continue

    if times[index][0] >= mainTime: # 시작 시간이 현재 시간 이상인가?
        isUseMeetingRoom = False
    else:
        index += 1
    
print(answer)