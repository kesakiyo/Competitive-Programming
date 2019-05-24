def func(n):
    if n == 0:
        return 1
    ret = 0
    for i in range(1, 4):
        if n - i >= 0:
            ret += func(n - i)
    return ret

t = int(input())
for _ in range(t):
    n = int(input())
    print(func(n))
