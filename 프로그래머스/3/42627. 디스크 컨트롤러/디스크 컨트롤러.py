import heapq
def solution(jobs):
    lis = []
    heapq.heapify(lis)

    time = 0
    task = 0
    index = 0
    size = len(jobs)
    start = -1

    while(index < size):
        for i in jobs:
            if time >= i[0] > start:
                heapq.heappush(lis,(i[1],i[0])) # 현재 

        if len(lis) == 0:
            time += 1
        else:
            spendTime,startTime = heapq.heappop(lis)
            start = time
            time += spendTime
            task += (time - startTime)
            index +=1
    
    return int(task/size)