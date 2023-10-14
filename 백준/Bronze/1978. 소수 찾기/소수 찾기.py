# 소수는 자신과 오직 1로만 나뉘는 수이므로
# 자신의 절반 수까지 나머지가 0인 것이 없으면 곧 소수이다
def checkSosu(num :int)->bool:
    if num < 2:
        return False

    maxCh = num//2 + 1

    for n in range(2,maxCh):
        if num % n == 0:
            return False
        
    return True

n = int(input())
result = 0

numb = list(map(int, input().split()))

for i in range(n):
    if checkSosu(numb[i]):
        result +=1

print(result)
