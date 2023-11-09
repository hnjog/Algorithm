import sys
inp = sys.stdin.readline

num = int(inp().strip()) # 도시 수

edges = list(map(int,inp().split()))        # 도시간 거리
oilValues = list(map(int,inp().split()))    # 해당 도시에서 기름값

# 그리디
# 다음 도시의 기름값이 현재 도시보다 크다면 현재 도시에서 채워감

sumValues = 0

for i in range(num - 1): # 어차피 마지막 도시의 기름값은 의미없으므로
    if oilValues[i] < oilValues[i+1]:
        oilValues[i+1] = oilValues[i]
    
    sumValues += (oilValues[i]*edges[i])

print(sumValues)