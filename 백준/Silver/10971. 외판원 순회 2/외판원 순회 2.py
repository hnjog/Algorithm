import sys

sys.setrecursionlimit(10**8)

# 외판원 순회2
# 대표적인 '브루트 포스' 알고리즘 중 하나
# 모든 도시를 이동하는 비용 중 가장 저렴한 녀석을 저장한다

# 개인적으로 짠 완전탐색 코드이지만 너무 느려서 알고리즘 찾아봄
# 조건 1. i i 는 항상 0
# 조건 2. 갈 수 없는 길이라면 0 값으로 표현됨
# 조건 3. 이미 간 도시라면 다시 갈 수 없음(시작 도시로 돌아오는 것 제외)
# 조건 4. 시작 도시는 임의로 지정

def circlesTest(dArr,nx):
    bVisit = [False] * nx
    sumVal = [0]
    minVal = [10000000]
    minSum = 10000000

    # 총 도시 수만큼 돌면
    # 다른 위치에서 시작시킨다
    for i in range(nx):
        startMove(dArr,nx,bVisit,sumVal,minVal, i,i)
        if minVal[0] < minSum:
            minSum = minVal[0]

        sumVal[0] = 0
        minVal[0] = 10000000
        bVisit = [False] * nx
    
    return minSum

# start 도시에서 시작한 경우의 '최소합'을 구하는 함수 (sumval 에 넘겨줌)
# 어차피 다 돌거 그냥 다 돈다
# 다만, 가려는 곳이 '이미 방문한 곳'인지 확인
# 추가적으로 갈 곳이 0이라면 못간다
def startMove(dArr,nx,bVisit,sumval,minVal, start,originStart):
    bVisit[originStart] = True
    
    if all(bVisit) == True:
        # 모든 도시를 방문했다면 다시 시작도시로 가야하므로 비용 더해줌
        if dArr[start][originStart] != 0 and sumval[0] + dArr[start][originStart] < minVal[0]:
            minVal[0] = sumval[0] + dArr[start][originStart]
        return
    
    # 이미 최종합보다 큰 상황이므로 가지치기
    if sumval[0] >= minVal[0]:
        return

    #돌기는 nx 번만 돌되, 중간에 재귀해야 함
    for i in range(nx):
        if bVisit[i] == True or dArr[start][i] == 0:
            continue

        #이제 i는 안가본 도시의 인덱스중 하나

        bVisit[i] = True
        sumval[0] += dArr[start][i]
        startMove(dArr,nx,bVisit,sumval,minVal,i,originStart)
        sumval[0] -= dArr[start][i]
        bVisit[i] = False
        
# 모든 순열을 고려하는 방식은 O(N!) 방식이기에 지나치게 느리다
# 현재까지 이 문제를 '다항'시간 안에 풀 수 있는 방법이 발견되지 않은 NP - Hard
# 알고리즘이 '다항 시간' 안에 동작하는 지 여부??
# -> 알고리즘의 시간 복잡도가 최악을 항상 넘지않는 경우,
#    다항 시간 안에 동작 (정확히는 다항식을 넘지 않는 경우)
# 참고 : https://gazelle-and-cs.tistory.com/64

# 결정론적 알고리즘 : 하나의 선택이 끝난 후, 다음을 선택(소모시간 : 모든 수행 단계)
# 비결정론적 알고리즘 : 병렬적으로 선택하며, 진행상황 공유(소모시간 : 성공한 수행 단계의 최댓값)
# 비결정론적 알고리즘은 결정론적 알고리즘의 '선택' 방식에 '힌트'를 검증한 것으로 대체할 수 있음

# p vs np
# P : 어떠한 결정론적 알고리즘으로 '다항 시간'내에 해결 가능한 문제
# np : 어떠한 비결정론적 알고리즘으로 '다항 시간'내에 해결 가능한 문제

# 일단 두 문제 집합은 '다항 시간'내에 풀 수 있는 것이 전제
# (비결정론이라도, 문제 자체의 깊이가 깊은 경우는 
# '다항 시간'내에 맞추지 못할 수 있으므로)
# (또한 결국 '알고리즘'의 동작 역시 '다항시간' 내여야 함)

# 결국 p는 np 에 포함된다고 하여도 과언은 아닐지도
# 모든 결정론적 알고리즘은 비결정론으로 해결할 수 있음
# 다만, 비결정론적 알고리즘으로는 해결하는 방법이 있지만
# 결정론적으로는 풀지못하는 문제가 하나라도 있으면 NP로 분류
# 애초에 대부분의 경우, NP에 속하지만, p에 속하는지는 모름
# P 와 NP가 다르다고 생각하지만 공인된 증명은 없다 한다

# 일단 TSP 문제는 NP 문제
# 근사 알고리즘을 통한 구현에 대하여 타협할 수 있는 부분
# 1. 모든 입력이 아닌 작은 입력만 고려 (10개 이내)
# 2. 시간 포기 (brute force를 사용하지만, 가망이 없어보이면 나중에..)
# 3. 최적해 포기 (결과가 나쁘지 않은 수준의 정확도)

# 다만 임의의 입력을 받는 TSP 알고리즘에 대해선 
# 근사 알고리즘이 존재 x (NP - Hard)
# 이 경우는 일단 브루트포스로 풀었음


if __name__ == "__main__":
    nx = int(sys.stdin.readline().strip())
    dArr = [[None for _ in range(nx)] for _ in range(nx)] # 리스트의 리스트 선언
    for i in range(nx):
        dArr[i] = list(map(int,sys.stdin.readline().split()))

    print(circlesTest(dArr,nx))
