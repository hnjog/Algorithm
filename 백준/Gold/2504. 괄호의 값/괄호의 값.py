import sys

# 요점은 임시변수를 통해
# 

def checkCalc(com)->int:
    stack = []
    resultValue = 0
    tempValue = 1 # result 에 더하기전의 임시변수

    for i in range(len(com)):
        if com[i] == '(':
            tempValue *= 2
            stack.append(com[i])
        elif com[i] == '[':
            tempValue *= 3
            stack.append(com[i])
        elif com[i] == ')':
            if not stack or stack[-1]!='(':
                resultValue = 0
                break
            if com[i-1] == '(':
                resultValue += tempValue
            tempValue //= 2
            stack.pop()
        elif com[i] == ']':
            if not stack or stack[-1]!='[':
                resultValue = 0
                break
            if com[i-1] == '[':
                resultValue += tempValue
            tempValue //= 3
            stack.pop()

    if stack:
        resultValue = 0

    return resultValue

if __name__ == "__main__":
    comman = sys.stdin.readline().strip()
    print(checkCalc(comman))