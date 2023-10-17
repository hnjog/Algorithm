import sys

sys.setrecursionlimit(10**8)

def bsSearchRecur(value,left,right,arr)->bool:
    if left > right:
        return False

    mid = (left + right)//2

    if arr[mid] == value:
        return True
    elif arr[mid] > value: # 중간값이 기준값보다 크기에 더 작은 쪽에 있다 생각
        return bsSearchRecur(value,left,mid-1,arr)
    
    return bsSearchRecur(value,mid+1,right,arr)

if __name__ == "__main__":
    nx = int(sys.stdin.readline().strip())
    #arr = [sys.stdin.readline().strip() for i in range(nx)]
    arr = list(map(int, sys.stdin.readline().split()))
    sx = int(sys.stdin.readline().strip())
    sarr = list(map(int,sys.stdin.readline().split()))

    arr.sort()
    for i in range(sx):
        if bsSearchRecur(sarr[i],0,nx-1,arr) == True:
            print(1)
        else:
            print(0)
