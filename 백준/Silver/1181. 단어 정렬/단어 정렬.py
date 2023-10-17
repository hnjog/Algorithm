import sys

if __name__ == "__main__":
    nx = int(sys.stdin.readline())
    strings = [sys.stdin.readline().strip() for i in range(nx)]

    setStrings = set(strings)
    
    resultString = []

    for i in setStrings:
        resultString.append(i)

    resultString.sort(key= lambda item : (len(item),item))

    for st in resultString:
        print(st)
