# 소수 체크
def checkSosu(num :int)->bool:
    if num < 2:
        return False

    maxCh = num//2 + 1

    for n in range(2,maxCh):
        if num % n == 0:
            return False
        
    return True

# 골드바흐의 추측
# 2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다
def goldBahsGuess(num : int):
    maxCheck = num // 2 + 1 # 절반부터 검사하면 될듯하다 어차피 절반으로 나누면 나머지는 큰쪽일테니
    minS = 0 # 작은 소수
    maxS = 0 # 큰 소수

    # 2부터 maxCheck까지 역순으로 반복문
    # range의 2번째 요소는 -1까지 이므로
    for i in range(maxCheck,1,-1):
        if checkSosu(i):
            checkNumber = num - i
            if checkSosu(checkNumber):
                maxS = checkNumber
                minS = i
                break

    if maxS < minS:
        a = maxS
        maxS = minS
        minS = a

    a = [minS,maxS]
    return a

n = int(input())

for i in range(n):
    num = int(input())
    resultA = goldBahsGuess(num)
    print(resultA[0])
    print(resultA[1])
