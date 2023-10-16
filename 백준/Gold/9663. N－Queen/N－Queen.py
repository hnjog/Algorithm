# N - Queen
# 정사각형 크기의 체스판이 주어진 경우
# 퀸 n개를 서로 공격할 수 없도록 배치하는 경우의 수를 구하기

# bottom-top 방식
# 행, 대각선 2개 에 대한 flag 처리 필요

import sys

def QueenSet(nx : int)->int:
    flag_Row = [False] * nx
    flag_left_Side = [False] * (nx * 2 - 1)     # / 대각선 (i+j)
    flag_right_Side = [False] * (nx * 2 - 1)    # \ 대각선 (i-j+nx)
    result = [0]

    QueenRecur(flag_Row,flag_left_Side,flag_right_Side,result,0,nx)

    return result[0]

def QueenRecur(rowFlag,leftSideFlag,rightSideFlag, result, start,n):
    if start >= n:
        return

    for i in range(n):                      # 결국 8번의 열을 다 돌아야 한다
        if (not rowFlag[i] and              # 행 체크
            not leftSideFlag[start + i] and         # 대각선 체크
            not rightSideFlag[start - i + (n-1)]):  # 대각선 체크
            if start == (n-1):
                result[0] += 1
            else:
                rowFlag[i] = leftSideFlag[start + i] = rightSideFlag[start - i + (n-1)] = True
                QueenRecur(rowFlag,leftSideFlag,rightSideFlag, result, start + 1,n)
                rowFlag[i] = leftSideFlag[start + i] = rightSideFlag[start - i + (n-1)] = False

# n번의 열을 다 돌며,
# 해당 인덱스의 행체크, 대각선 체크를 실행
# 이미 체크 된 경우 아예 i가 다음으로 넘어간다
# start를 점진적으로 증가시키며 배열의 마지막(크기 -1) 도달 시
# result +=1 (이거 뮤터블이라 이렇게 했...)
# 문제없을시 일단 '다음'으로 넘어간다
# flag는 재귀에서 들어갈때, 체크해주며, 나올때 풀어준다

# '다음' 행에서도 같은 검사를 해야하기에 , start를 증가시킨후 반복한다

if __name__ == "__main__":
    nx = int(sys.stdin.readline())
    count = QueenSet(nx)
    print(count)