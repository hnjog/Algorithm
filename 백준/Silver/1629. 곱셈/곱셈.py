import sys 

sys.setrecursionlimit(10**8)

# 지수법칙 : a^(n+m) = a^n * a^m
# 모듈러 연산 : (a*b)%c = ((a%c)*(b%c))%c

def Mul(a,b,c)->int:
    if b == 0: # 0번 곱하면
        return 1 # 그냥 n^0 = 1
    
    # A^b % c => A^(b//2) % c * A^(b//2) % c => ....
    # 그러나 실제로 재귀를 2번 돌릴 필요는 없음

    # 어차피 tmp는 같은 값이기에 그냥 tmp * tmp % c 로 
    # 한번에 해결 가능
    
    tmp = Mul(a,b//2,c)

    tmp = tmp * tmp % c
    if b%2 == 0:
        return tmp
    
    return a * tmp % c

if __name__ == "__main__":
    n1,n2,n3 = sys.stdin.readline().split()
    n1 = int(n1)
    n2 = int(n2)
    n3 = int(n3)

    print(Mul(n1,n2,n3))
