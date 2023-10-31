import sys

inp = sys.stdin.readline

num = int(inp().strip())

nList = list(map(int,inp().split()))

# lcs 변형
# 같은 문자열 2번 비교

# 아무리 수열이 작아도 최소 1의 길이가 보장됨
dp = [1 for _ in range(num)]

# dp[i] = nList[i]를 마지막 값으로 가지는 가장 긴 증가부분 수열의 길이

for i in range(num):
    # 1 ... i 까지 반복문을 돌려
    # dp를 채운다
    for j in range(i): # 이게 num이여도 정답이지만... 기본적으론 정의에 어긋나고 가독성이 떨어진다
        if nList[i] > nList[j]: # 현재 문자열이 다른 문자열보다 크다면
            dp[i] = max(dp[i],dp[j]+1) # 가장 긴 증가 부분 수열의 길이를 가진 녀석보다 1 크게 만들어준다

# dp 중 가장 긴 수를 반환한다
print(max(dp))