import sys

sys.setrecursionlimit(10**8)

# 이진 탐색 적용방식
# 알고리즘 적용 방식에 대하여
# 가장 짧은 길이를 start로
# 가장 긴 길이를 left로 두고
# sum을 넘기는지 확인
# '나무 길이'가 반드시 배열에 포함되어 있다는 말이 없기에
# index 방식은 x
def calcHeight(start : int, end : int,arr,needTreeMeter)->int:
    if start > end:
        return end

    mid = (start + end) // 2
    
    sum = 0
    for i in arr:
        if i > mid:
            sum += (i - mid)

    # 넘치는 상황    
    if sum >= needTreeMeter:
        return calcHeight(mid + 1,end,arr,needTreeMeter)

    # 부족한데??
    return calcHeight(start,mid-1,arr,needTreeMeter)
    
if __name__ == "__main__":
    nx,needTreeMeter = sys.stdin.readline().split()
    nx = int(nx)
    needTreeMeter = int(needTreeMeter)
    arr = list(map(int, sys.stdin.readline().split()))
    
    arr.sort()
    print(calcHeight(1,arr[nx-1],arr,needTreeMeter))