import sys

# 주어진 수가 10보다 작으면 0을 붙여 2자리수 만들고,
# 각 자리의 수를 더함
# 그 다음 주어진 수의 가장 오른쪽 자리 수와 앞에서 구한 오른쪽 자리 수를 이어 붙이면 새로운 수
# 26 -> 2 + 6 = 8
# 6과 8을 붙여 68
# 6 + 8 = 14
# 8과 가장 뒷자리 4를 합쳐 84
# 8 + 4 = 12
# 4와 가장 뒷자리 4를 합쳐 42
# 4 + 2 = 6
# 26 으로 돌아옴 (4번)
# 답은 4번

# 일단 입력은 1~99
def countCheck(num,origin,count):
    if num == origin and count[0] != 0:
        return 0
    
    count[0] +=1

    n1 = num // 10
    n2 = num % 10

    nSum = n1+n2
    
    newNum = n2 * 10 + nSum % 10
    
    countCheck(newNum,origin,count)

if __name__ == "__main__":
    num = int(sys.stdin.readline().strip())
    if num == 0:
        print(1)
    else:
        count = [0]
        countCheck(num,num,count)
        print(count[0])

