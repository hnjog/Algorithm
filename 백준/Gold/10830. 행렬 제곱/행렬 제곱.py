import sys 

sys.setrecursionlimit(10**8)

# 행렬의 곱
def arrayMul(darr1,darr2):
    n = len(darr1)
    resultArr = [[0]*n for _ in range(n)]
    
    # 행렬을 돈다
    for row in range(n):
        for col in range(n):
            e = 0
            # 값 꺼내야 하므로 반복문 한번 더 돈다
            for i in range(n):
                e += darr1[row][i] * darr2[i][col]
            resultArr[row][col] = e % 1000
    
    return resultArr

def process(darr,powCount):
    dLen = len(darr)
    # 제곱 횟수가 1이면 1000 나누고 보내준다
    if powCount == 1:
        for i in range(dLen):
            for j in range(dLen):
                darr[i][j] %= 1000

        return darr
    
    tmp = process(darr,powCount//2)

    # 지수가 2로 나뉘어 지므로 제곱한 배열 반환
    if powCount % 2 == 0:
        return arrayMul(tmp,tmp)
    
    # 지수가 하나 남으므로, 제곱 후, 원본 배열도 같이 곱해줘 처리한다
    return arrayMul(arrayMul(tmp,tmp),darr)

if __name__ == "__main__":
    arSize, powSize = sys.stdin.readline().split()
    arSize = int(arSize) 
    powSize = int(powSize)
    dArr = [list(map(int,sys.stdin.readline().split())) for _ in range(arSize)]

    # 처리 함수
    result = process(dArr,powSize)

    for i in range(arSize):
        for j in range(arSize):
            print(f"{result[i][j]} ",end ='')
        print('')
    

