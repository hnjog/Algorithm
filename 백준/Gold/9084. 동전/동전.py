import sys

inp = sys.stdin.readline

testN = int(inp().strip())

for i in range(testN):
    cNum = int(inp().strip())           # 동전의 가지수는 1~20
    coins = list(map(int,inp().split())) # 동전은 중복되지 않는다
    mv = int(inp().strip())             # 목표 금액은 1~10000
    dp = [1] + [0] * mv                 # 경우의 수 dp 테이블 (0원은 어떤 동전값이라도 만들 수 있음)


    for j in range(cNum): # 코인 반복문 돌면서 체크하기
        for i in range(1,mv + 1):
            if coins[j] <= i:
                dp[i] += dp[i - coins[j]]

    print(dp[mv])