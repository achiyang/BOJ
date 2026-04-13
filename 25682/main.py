import sys

arr = [[0] * 2001 for _ in range(2001)]

n, m, k = map(int, input().split())

for i in range(1, n+1):
    line = sys.stdin.readline()
    for j in range(1, m+1):
        c = 'W' if (i + j) % 2 == 0 else 'B'
        arr[i][j] = (1 if line[j - 1] == c else 0) + arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1]

minChange = 2000000
for i in range(k, n+1):
    for j in range(k, m+1):
        a = arr[i][j] - arr[i][j - k] - arr[i - k][j] + arr[i - k][j - k]
        minChange = min(minChange, a, k*k-a)

print(minChange)