import sys

def f(a, b):
    ret = 1
    a %= 10

    while (b):
        if (b % 2 == 1):
            ret = (ret * a) % 10
        a = (a * a) % 10
        b = b // 2

    if (ret):
        return ret
    else:
        return 10

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    print(f(a, b))
