import sys
import math

inp = sys.stdin.readline

m, n, k = map(int, inp().split())

board = [inp().strip() for _ in range(m)]

# 시간 초과 중
# 어떻게 하면 이걸 풀 수 있지??
# 일단 브루트 포스로는 시간초과
# 당연히 O(n^4)
# DP로 풀 수 있나?
# '누적합'과 '구간 합'의 개념이 필요한 문제
# '누적합' 은 0부터 특정한 인덱스까지의 합
# '구간합'은 누적합의 특정한 부분끼리 뺌으로서 (ex i와 j)
# 그 사이 요소의 합을 구한다는 것이다

# 따라서 흰색과 검은색 각각의 누적합을 구하고
# 이후, k 사이즈에 대한 구간합을 전체 배열을 돌며 가장 작은 값을 구하는 방식이다
# 일단 양 옆(i+1 과 j+1) 은 s(i,j)에 각 요소를 더한 것과 같다
# 2차원 누적합의 기본 개념은 s(i,j) = s(i-1,j) + s(i,j-1) - s(i-1,j-1) + (i,j) 이다
# 이후, 구간합을 구하고, 그 중 가장 작은 값을 반환한다
#


def minboardPaintCount(m: int, n: int, k: int, startColor) -> int:
    prefix_sum = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

    # 누적합 구하기
    for i in range(m):
        for j in range(n):
            value = 0
            if (i + j) % 2 == 0:
                value = board[i][j] != startColor
            else:
                value = board[i][j] == startColor

            prefix_sum[i + 1][j + 1] = (
                prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - prefix_sum[i][j] + value
            )

    count = math.inf

    # 구간합 구하기
    for i in range(
        1, m - k + 2
    ):  # for 때문에 +1, 그리고 생성했을때 첫열은 0으로 쓰기위해 배열 크기가 +1 되었으므로 +1
        for j in range(1, n - k + 2):
            # 기존 값과 새로 구한 구간합과 비교
            # 구간 합은 누적합에서 '특정한 부분 끼리 뺀 요소'라는 점을 잊지 말것
            # prefix_sum[i-1][j-1] - prefix_sum[i+k-1][j-1] - prefix_sum[i-1][j+k-1] + prefix_sum[i+k-1][j+k-1]
            # 해당 요소는 결국 i 부터 k 및 j부터 k까지의 누적합 끼리의 뺄샘이다
            # Range(x1, y1, x2, y2) = S(x2, y2) - S(x2, y1 -1) - S(x1 - 1, y2) + S(x1 - 1 , y1 -1) (이것과 같음)
            # x2,y2는 0부터 x2,y2 2차원 배열의 누적합이다 (S(x2, y2))
            # 따라서 0~x1 및 0~y1의 요소들은 빼준다(- S(x2, y1 -1) - S(x1 - 1, y2))
            # 다만 이 때 x1,y1 의 요소가 두번 빼지기에 한번 더해서 올바른 값으로 만든다

            # 기존 누적합 인 prefix_sum[i+k-1][j+k-1] 에서
            # 각 x 축과 y축인 누적합을 빼주되 (- prefix_sum[i+k-1][j-1] - prefix_sum[i-1][j+k-1])
            # 공통된 부분인 [i][j] 부분은 두 번뺏으니 한번 더해주는 것이다 (+ prefix_sum[i-1][j-1])
            count = min(
                count,
                prefix_sum[i + k - 1][j + k - 1]
                + -prefix_sum[i + k - 1][j - 1]
                - prefix_sum[i - 1][j + k - 1]
                + prefix_sum[i - 1][j - 1],
            )

    return count


print(min(minboardPaintCount(m, n, k, "W"), minboardPaintCount(m, n, k, "B")))
