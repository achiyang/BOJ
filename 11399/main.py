import sys

input = sys.stdin.readline

n = int(input())
p = list(map(int,input().split()))
p.sort()
print(sum(p[i] * (n - i) for i in range(n)))