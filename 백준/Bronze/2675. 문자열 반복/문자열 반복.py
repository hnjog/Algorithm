tryCount = int(input())

for i in range(tryCount):
    a,st = input().split()
    count = int(a)
    result = ""
    for c in st:
        for j in range(count):
            result += c

    print(result)