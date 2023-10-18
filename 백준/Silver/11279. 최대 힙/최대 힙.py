import sys

# 음... 그냥 데이터 들어올때마다

import queue

if __name__ == "__main__":
    nx = int(sys.stdin.readline().strip())
    #arr = [sys.stdin.readline().strip() for i in range(nx)]
    #arr = list(map(int, sys.stdin.readline().split()))
    #dArr = [[None for _ in range(nx)] for _ in range(nx)]
    
    commandArr = [None] * nx
    for i in range(nx):
        commandArr[i] = int(sys.stdin.readline().strip())

    # arr =[]
    # heapq._heapify_max(arr) # 최대힙 변환
    priorQ = queue.PriorityQueue(nx)

    for i in range(nx):
        inp = commandArr[i]
        # if inp == 0:
        #     if len(arr) == 0:
        #         print(0)
        #     else:
        #         print(heapq._heapify_max(arr))
        if inp ==0:
            if priorQ.empty() == True:
                print(0)
            else:
                print(priorQ.get()[1])
        else:
            priorQ.put((-inp,inp)) # max heap이 필요하기에, priority를 낮추어 저장

    