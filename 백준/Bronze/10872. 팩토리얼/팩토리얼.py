def facto(num : int) -> int:
    if num < 2:
        return 1
    return num * facto(num - 1);

n = int(input())
print(facto(n))