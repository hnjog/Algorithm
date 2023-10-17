import sys

if __name__ == "__main__":
    nx = int(sys.stdin.readline().strip())
    commandArr = [sys.stdin.readline().strip() for i in range(nx)]
    #arr = list(map(int, sys.stdin.readline().split()))
    stack = []
    stackSize = 0

    for i in commandArr:
        ar = list(i.split())
        if ar[0] == "push":
            stack.append(ar[1])
            stackSize += 1
        elif ar[0] == "pop":
            if stackSize <= 0:
                print(-1)
                stackSize = 0
            else:
                print(stack[stackSize-1])
                stack.pop()
                stackSize -= 1
        elif ar[0] == "size":
            print(stackSize)
        elif ar[0] == "empty":
            if stackSize <= 0:
                print(1)
                stackSize = 0
            else:
                print(0)
        elif ar[0] == "top":
            if stackSize <= 0:
                print(-1)
                stackSize = 0
            else:
                print(stack[stackSize-1])

