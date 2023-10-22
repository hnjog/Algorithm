import sys
inp = sys.stdin.readline

sys.setrecursionlimit(10**8)

# DFS
# nums을 '노드'처럼 여긴뒤,
# 4가지 수식 중 사용하면서 DFS로 파고나가는 방식으로 해야할듯..?

nNum = int(inp().strip())
nums = list(map(int,inp().split()))
commands = [0,0,0,0]

iCom = list(map(int,inp().split()))

for i in range(len(iCom)):
    commands[i] = iCom[i]

minV = 1000000000
maxV = -1000000000

# 입력 끝

useCommands = [0,0,0,0]

# dfs로 계속 들어가면서 연산할 녀석
# 사용한 커맨드 배열, 현재까지의 수식값, 진행도
# 4가지 배열을 돌면서 useCommands의 요소가 아직 그것보다 작은 녀석을 dfs로 파고 들어간다
# 나누기 시,양수로 바꾼 뒤, 몪을 취하고 다시 음수로 바꿔주기
def dfsOperator(useCommands,sum, process):
    # 최댓
    if process >= nNum:
        global maxV
        global minV
        if sum > maxV:
            maxV = sum
        if sum < minV:
            minV = sum
        return

    #for i in range(process,nNum):
    for j in range(4):
        if useCommands[j] < commands[j]:
            useCommands[j] += 1
            if j == 0 : # +
                dfsOperator(useCommands,sum + nums[process],process + 1)
            elif j == 1: # -
                dfsOperator(useCommands,sum - nums[process],process + 1)
            elif j == 2: # -
                dfsOperator(useCommands,sum * nums[process],process + 1)
            else:
                modValue = sum
                if modValue < 0:
                    modValue *= -1
                    modValue = modValue // nums[process]
                    modValue *= -1
                else:
                    modValue = modValue // nums[process]

                dfsOperator(useCommands,modValue,process + 1)
            
            useCommands[j] -= 1

dfsOperator(useCommands,nums[0],1)

print(maxV)
print(minV)
