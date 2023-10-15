from typing import Any, MutableSequence

def asend(lst :list)->None:
    lstLength = len(lst)
    # 삽입정렬
    # n번째 요소가 n-1보다 작은 경우
    # 해당 위치에 삽입해준다
    for i in range(lstLength):
        for j in range(i):
            if lst[i] < lst[j]:
                a = lst[i]
                lst.pop(i)
                lst.insert(j,a)

if __name__ == "__main__":
    leng = int(input())
    lst = [0] * leng
    for i in range(leng):
        lst[i] = int(input())
    
    asend(lst)

    for i in range(leng):
        print(lst[i])
