import sys

# 문제를 정리하면
# 각 '수열' 의 합이 sum이 되는 '부분수열'의 개수를 구하는 것이며
# 밑에서부터 위를 보면 안된다 (중복)

def countP(sum : int, arr : list)->int:
    count = [0]
    testAr = []

    dfs(sum,0,arr,0,count)

    return count[0]

def dfs(sum,currentS,arr,process,answer): #nowIndex , testAr
    # 종료조건
    arrLen = len(arr)
    if process > arrLen -1: 
        return
    
    currentS += arr[process]

    if sum == currentS:
        answer[0] +=1 # 찾았다

    dfs(sum,currentS,arr,process + 1,answer)

    dfs(sum,currentS - arr[process],arr,process + 1,answer)

if __name__ == "__main__":
    num, sum = map(int,sys.stdin.readline().split())
    arr = list(map(int,sys.stdin.readline().split()))

    print(countP(sum,arr))