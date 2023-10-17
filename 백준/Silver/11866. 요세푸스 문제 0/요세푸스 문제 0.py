import sys

def yo(arr,k):
    answer= []

    i = 0
    while len(arr) > 0:
        i += (k-1)
        i %= len(arr)
        answer.append(arr[i])
        arr.remove(arr[i])

    return answer

if __name__ == "__main__":
    #nx = int(sys.stdin.readline().strip())
    #arr = [sys.stdin.readline().strip() for i in range(nx)]
    #arr = list(map(int, sys.stdin.readline().split()))
    #dArr = [[None for _ in range(nx)] for _ in range(nx)] # 리스트의 리스트 선언
    a = list(map(int,sys.stdin.readline().split()))
    n = a[0]    # 1~n번의 사람들
    k = a[1]    # k 

    arr = []
    for i in range(n):
        arr.append(i+1)
    
    ans = yo(arr,k)

    print("<", end = '')
    for i in range(len(ans) - 1):
        print(f"{ans[i]}, ",end ='')

    print(f"{ans[len(ans) - 1]}>")