import sys

inp = sys.stdin.readline

testnum = int(inp().strip())

for i in range(testnum):
    num = int(inp().strip())
    # 지원자의 순위 (각각)
    # 어떤 지원자의 성적이 다른 지원자보다 '모두' 떨어진다면
    # 그는 선발되지 못한다
    coList = [list(map(int,inp().split())) for _ in range(num)]
    coList.sort()
    answer = num

    critIndex = 0

    for j in range(1,num):
        if coList[critIndex][1] < coList[j][1]:
            answer -= 1
        else:
            critIndex = j
    
    print(answer)
    