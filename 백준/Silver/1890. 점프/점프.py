import sys

sys.setrecursionlimit(10**8)

inp = sys.stdin.readline

n = int(inp().strip())

dp = [[0 for _ in range(n)]for _ in range(n)]
val = [list(map(int,inp().split())) for _ in range(n)]

def dfs(x,y)->int:
    if x == n-1 and y == n-1:
        return 1
    
    if val[x][y] == 0:
        return 0

    if dp[x][y] != 0:
        return dp[x][y]

    sum = 0
    for nx,ny in [(x+val[x][y],y),(x,y+val[x][y])]:
        if 0<= nx <n and 0 <=ny<n:
            sum += dfs(nx,ny)

    dp[x][y] = sum 

    return sum

print(dfs(0,0))