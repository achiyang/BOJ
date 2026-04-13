N = int(input())
digit = len(str(N))
constructor = 0

for i in range(max(1, N - digit * 9), N - digit + 1):
    if i + sum(map(int, list(str(i)))) == N:
        constructor = i
        break

print(constructor)