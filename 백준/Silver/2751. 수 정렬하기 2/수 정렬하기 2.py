import sys 
from typing import Any, MutableSequence

sys.setrecursionlimit(10**8)

def mergeSort(lst:MutableSequence)->None:
    n = len(lst)
    buff = [None] * n
    _merge_Sort_Recur(lst,buff,0,n-1)
    del buff

def _merge_Sort_Recur(lst:MutableSequence,buff :MutableSequence,left :int,right:int)->None:
    if left < right:
        mid = (left+right) // 2

        _merge_Sort_Recur(lst,buff,left,mid)     # 배열의 앞 부분
        _merge_Sort_Recur(lst,buff,mid+1,right)  # 배열의 뒷 부분

        # buffs index
        buffHalfs = 0 # buff의 최댓값을 가리키는 인덱스
        buffIndex = 0 # buff(뒷부분 배열)을 가리키는 인덱스

        # lst index       
        i = left    # lst의 뒷부분을 가리키는 용도의 인덱스(처음에 buffHalf와 같이 올려준다)
        k = left    # lst의 앞부분을 가리키는 용도의 인덱스(점점 올라가며 삽입할 위치를 찾음)

        # 배열의 앞부분(lst[left]~lst[mid])을
        # buff[0]~buff[mid - left] 로 복사
        while i <= mid:
            buff[buffHalfs] = lst[i]
            i +=1
            buffHalfs +=1
        # 종료시점의 buffHalfs값은 mid - left + 1
        
        # 배열의 뒷 부분(lst[mid + 1]~lst[right])과
        # buff로 복사한 배열의 앞부분 buffHalfs 개를
        # 병합한 결과를 lst에 저장
        while i<=right and buffIndex < buffHalfs:
            if buff[buffIndex] <= lst[i]: # lst의 뒷부분 요소가 buff(현재 배열 앞부분) 보다 작은 경우
                lst[k] = buff[buffIndex] # buff 요소를 k에 넣어준다
                buffIndex+=1
            else:
                lst[k] = lst[i] # 그게 아니면 뒷부분 값을 넣어주고, i를 올린다
                i +=1
            k +=1

        # buff에 남아있는 원소를 배열 lst에 복사하기
        while buffIndex < buffHalfs:
            lst[k] = buff[buffIndex]
            k+=1
            buffIndex+=1

        # 요점은 배열의 앞부분과 뒷부분을 따로 쓴다는 점이며
        # 약 4개의 index를 사용하여

if __name__ == "__main__":
    leng = int(sys.stdin.readline())
    lst = [None] * leng
    for i in range(leng):
        lst[i] = int(sys.stdin.readline())
    
    mergeSort(lst)

    for i in range(leng):
        print(lst[i])
