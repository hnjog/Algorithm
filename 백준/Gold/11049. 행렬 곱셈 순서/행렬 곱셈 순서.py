import sys
import math

# 연쇄 행렬 곱셈
# dp[i][j] : i번째 행렬부터 j번째 행렬까지 곱했을 때의 최소 곱셈 연산 횟수
# dp[i][i] = 0 : 행렬이 하나이기에 곱셈이 일어나지 않음

# k가 1부터 j-1 까지 순회하면서 결합의 위치를 나누어주는 변수
# di * dk * dj -> 곱셈 연산 횟수 (di x dk, dk x dj 배열)
# dp[1][4] = dp[1][k] + dp[k+1][4] + d1 * dk * d4
# dp[1][4] : 1번째 행렬부터 4번쨰 행렬까지 곱했을 때의 최소 곱셈 연산 횟수
# dp[1][k] + dp[k+1][4] 는 dp[1][1] + dp[2][4], dp[1][2] + dp[3][4], dp[1][3] + dp[4][4]의
# 결과 중 최솟값이 들어있음
# 최종적인 점화식은
# dp[i][j] = min(dp[i][k] + dp[k+1][j] + d(i-1) * dk * dj) (다만 i <= k <= j-1)


inp = sys.stdin.readline

num = int(inp().strip())

origin = []

for i in range(num):
    r,c = map(int,inp().split())
    origin.append((r,c))

dp = [[math.inf for _ in range(num)] for _ in range(num)]

for i in range(num):
    dp[i][i] = 0

for i in range(1,num):
    for j in range(num - i):
        for k in range(j,j+i):
            dp[j][j+i] = min(dp[j][j+i],
                             dp[j][k] + dp[k+1][j+i] + origin[j][0] * origin[k][1] * origin[j+i][1])

print(dp[0][num-1])