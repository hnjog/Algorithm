import sys

sys.setrecursionlimit(10**8)

# 안전 영역
# 비에 잠기지 않은 영역 중
# 서로 이어져 있는 경우(대각선 x)는 같이 세어
# 안전영역의 총 개수중 가장 큰 것 구하는 것
# -> 안전 영역의 총 개수는 k를 넘지 않는다
# 비는 임의로 온다고 가정(오지 않을 수도 있음) 

# 푸는 방법?
# DFS 로 푼다 (직접 풀었다기 보단 정답 코드를 수정)

# 요점에 대하여
# 여기 안잠겼고, 누가 방문을 안했다면 안전 영역인것은 확정(+1)
# 근처 돌아보면서 안잠긴 녀석들 찾아보고, 그 녀석들이랑은
# '이어져' 있는 것이므로 다 방문 체크 해준다

def countSafetyZone(zone,limit)->int:
    maxCount = 1

    # darr 중 가장 큰 요소까지만 돌린다(max(map(max,darr)))
    for rain in range(max(map(max,zone))):
        bVisit = [[False]*limit for _ in range(limit)]
        count = 0
        # 비 채우기
        for i in range(limit):
            for j in range(limit):
                # 처음에 들어갈 때,
                if (zone[i][j] > rain # 침수되지 않았으며
                    and not bVisit[i][j]): # 방문하지 않은 곳에만 들어감
                    count+=1    # count 더해주고, 연관된 녀석들에게 bVisit 체크
                    bVisit[i][j] = True
                    dfs(zone,limit,bVisit,i,j,rain) # 내부 돌면서 안잠긴 녀석들은 다 방문
        
        if maxCount < count:
            maxCount = count

    return maxCount

def dfs(zone,limit,bVisit,x,y,rain)->bool:
    # 상 우 하 좌
    # for 문 안쓰는것보단 이게 더 깔끔
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if ((0 <= nx < limit) and (0 <= ny < limit)
             and not bVisit[nx][ny]
             and zone[nx][ny] > rain):
            bVisit[nx][ny] = True
            dfs(zone,limit,bVisit,nx,ny,rain)


if __name__ == "__main__":
    nx = int(sys.stdin.readline().strip())
    dArr = [list(map(int,sys.stdin.readline().split())) for _ in range(nx)]

    print(countSafetyZone(dArr,nx))