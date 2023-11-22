import sys

DIVIDE_VALUE = 1000000007

inp = sys.stdin.readline
sys.setrecursionlimit(10**8)

# DP 방식으로 푸는 방식
# top-down
dp = dict()

# n이 짝수일 떄와 홀수일 때의
# 공식을 다르게 하여 구함


def fibo(n):
    if dp.get(n):
        return dp[n]
    if n == 0:
        return 0
    if n <= 2:
        return 1

    if n % 2 == 0:
        dp[n // 2 + 1] = fibo(n // 2 + 1) % DIVIDE_VALUE
        dp[n // 2 - 1] = fibo(n // 2 - 1) % DIVIDE_VALUE
        return dp[n // 2 + 1] ** 2 - dp[n // 2 - 1] ** 2

    dp[n // 2 + 1] = fibo(n // 2 + 1) % DIVIDE_VALUE
    dp[n // 2] = fibo(n // 2) % DIVIDE_VALUE
    return dp[n // 2 + 1] ** 2 + dp[n // 2] ** 2


n = int(inp().strip())

print(fibo(n) % DIVIDE_VALUE)
