# 일단 내가 생각한 방법
# 일단 하노이 탑의 가장 밑부분을 1 -> 3으로 옮겨야 하며
# 이 때 2번 의 탑에는 n - 1 의 하노이 탑이 생성됨
# 또한 2번의 탑의 마지막 밑부분을 빼려면 1에 n -2 의 하노이 탑이 생성
# ... 
# 마지막으로 1 혹은 2에 남아있는 하노이의 탑이 3으로 옮겨가며 마무리됨

# k인 녀석은 3번에 가야한다
# k-1 인 녀석은 자신(1일떄는 2, 2일때는 1)의 위치로 가야함
# 또한 k-2 인 녀석은 'no visit'의 위치로는 이동할 수 없음

# 현재는 k에서 1로 이동하는 것만 고려된 것
def hanoiMove(start,to,novis,n):
    if(n < 1):
        return
    hanoiMove(start, novis, to, n-1) # k-1 녀석을 시작점에서 novis로 옮겨야 함 (이번에 to는 방문하지 않음)
    print(start,to)
    hanoiMove(novis,to,start,n-1) # k 녀석을 시작점에서 목적지로 옮겨야 함

a = int(input())
result =pow(2,a) - 1
print(result)
if a <= 20:
    hanoiMove(1,3,2,a) # 첫번째 원반을 3번으로 옮기고 2번을 novisit로 두고 시작

