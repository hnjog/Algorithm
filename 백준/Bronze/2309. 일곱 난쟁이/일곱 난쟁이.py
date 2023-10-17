import sys

sys.setrecursionlimit(10**8)

# 일곱 난쟁이의 키의 합은 100
# 여러 정답이 가능하다면 아무거나 출력

# N Queen 과 비슷하지만,
# 이 녀석은 그저 발견만 하면 바로 탈출하면 된다
# 또한 배열의 개수는 9이고 리미트는 7인 점에 유의하자

# sum : 합
# start : 시작할 위치
# num : 현재 센 난쟁이의 수
# nine_ar : 아홉난쟁이 수 배열
# seven_ar : 정답용 배열
# find : 찾았는가??

def checkSmallHeightSum(sum,start,num,nine_ar,seven_ar,find):
    if num[0] >= 7:
        return

    for i in range(start, len(nine_ar)):
        sum[0] += nine_ar[i]
        seven_ar[num[0]] = nine_ar[i]
        num[0] += 1

        if sum[0] == 100 and num[0] == 7:
            find[0] = True
            return
        
        checkSmallHeightSum(sum,start + 1,num,nine_ar,seven_ar,find)

        if find[0] != True:
            sum[0] -= nine_ar[i]
            num[0] -= 1
        else:
            return

if __name__ == "__main__":
    #nx = int(sys.stdin.readline().strip())
    #= [sys.stdin.readline().strip() for i in range(nx)]
    nine_Small = [0] * 9
    for i in range(9):
        nine_Small[i] = int(sys.stdin.readline().strip())

    seven_Small = [0] * 7
    sum = [0]
    num = [0]
    find = [False]
    checkSmallHeightSum(sum,0,num,nine_Small,seven_Small,find)

    seven_Small.sort()

    #print('answer:')
    for i in range(7):
        print(seven_Small[i])


