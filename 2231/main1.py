N = int(input())
digit = len(str(N))
constructor = 0

for i in range(N - digit * 9, N - digit + 1):
    temp = i
    sum = i
    while temp > 0:
        sum += temp % 10
        temp //= 10
    if sum == N:
        constructor = i
        break

print(constructor)