import sys

N = int(sys.stdin.readline())

meetings = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]

meetings.sort(key=lambda x: (x[1], x[0]))

count = 1
end = meetings[0][1]
for i in range(1, N):
    if end <= meetings[i][0]:
        end = meetings[i][1]
        count += 1

print(count)