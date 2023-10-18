import sys
from collections import deque

if __name__ == "__main__":
    num = int(sys.stdin.readline().strip())
    heights = list(map(int,sys.stdin.readline().split()))
    stack =[]
    answer = [0] * num

    for i in range(num):
        # stack에 데이터 존재 시
        while stack:
            # 가장 마지막에 저장한 데이터와 비교
            if stack[-1][1] > heights[i]:
                # 정답 코드에 넣어준다
                answer[i] = stack[-1][0] + 1
                break
            else:
                # 필요없는 녀석이니 버린다
                stack.pop()

        # 해당 데이터 넣어준다
        stack.append([i,heights[i]])

    for i in answer:
        print(f"{i} ", end = '')

