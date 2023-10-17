import sys

# 직접 구현하기보다는 '선형'큐의 개념만 가져와 사용
# 실제로 구현하는 경우는 원형 큐의 클래스를 사용하거나
# collections를 사용하는 방식 권장

if __name__ == "__main__":
    nx = int(sys.stdin.readline().strip())
    commandArr = [sys.stdin.readline().strip() for i in range(nx)]
    #arr = list(map(int, sys.stdin.readline().split()))
    queue = []
    #queueSize = 0
    front = 0
    back = 0

    for i in commandArr:
        ar = list(i.split())
        if ar[0] == "push":
            queue.append(ar[1])
            back += 1
        elif ar[0] == "pop":
            if back <= front:
                print(-1)
                back = front
            else:
                print(queue[front])
                #queue.remove(queue[0])
                front += 1
        elif ar[0] == "size":
            print(back - front)
        elif ar[0] == "empty":
            if back <= front:
                print(1)
                back = front
            else:
                print(0)
        elif ar[0] == "front":
            if back <= front:
                print(-1)
                back = front
            else:
                print(queue[front])
        elif ar[0] == "back":
            if back <= front:
                print(-1)
                back = front
            else:
                print(queue[back - 1])

