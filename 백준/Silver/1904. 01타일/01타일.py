import sys
inp = sys.stdin.readline

n = int(inp().strip())

def count(n:int)->int:
    share = n % 3

    dp = [0,1,2]
    ind = 1
    for i in range(1,n):
        if ind % 3 == 0:
            dp[2] = dp[1]% 15746 + dp[0]% 15746
            ind //= 3
        elif ind % 2 == 0 :
            dp[1] = dp[0]% 15746 + dp[2]% 15746
            ind +=1
        else:
            dp[0] = dp[1]% 15746 + dp[2]% 15746
            ind +=1

    result = dp[share] % 15746

    return result

print(count(n))