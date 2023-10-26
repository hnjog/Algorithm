import sys

# A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수
# 해당 조건에 따라서
# 탐욕 선택 속성 에 만족한다 판단

inp = sys.stdin.readline

n,k = map(int,inp().split())

coins = [0] * n

for i in range(n):
    coins[i] = int(inp().strip())

coins.reverse()

count = 0
index = 0

while k > 0:
    if k >= coins[index]:
        temp = int(k // coins[index])
        count += temp
        k -= coins[index] * temp
    
    index += 1

print(count)
