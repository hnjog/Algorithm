import sys

def finboFunc(n:int)->int:
    dp = [0] * 91
    dp[1] = 1
    for i in range(2,n + 1):
        dp[i] = dp[i-1] + dp[i-2]
    
    return dp[n]

num = int(sys.stdin.readline().strip())

print(finboFunc(num))