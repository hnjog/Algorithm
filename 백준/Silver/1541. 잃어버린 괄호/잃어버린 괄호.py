import sys

inp = sys.stdin.readline

st = inp().strip()

strInd = 0
flag = False
sum = 0
for i in range(len(st)):
    if st[i] == '-' or st[i] == '+':
        if flag == True:
            sum -= int(st[strInd:i])
        else:
            sum += int(st[strInd:i])

        if st[i] == '-' and flag == False:
            flag = not flag
        strInd = i + 1

if flag == True:
    sum -= int(st[strInd:len(st)])
else:
    sum += int(st[strInd:len(st)])

print(sum)