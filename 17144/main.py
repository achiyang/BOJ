import sys

input = sys.stdin.readline

DRC = ((1, 0), (0, 1), (-1, 0), (0, -1))

R, C, T = map(int, input().strip().split())

board = []
temp = [[0]*C for _ in range(R)]
cleaner = 0

def spread():
    for i in range(R):
        for j in range(C):
            temp[i][j] = 0

    for i in range(R):
        for j in range(C):
            if board[i][j] >= 5:
                n = board[i][j] // 5

                for dr, dc in DRC:
                    nr = i + dr
                    nc = j + dc

                    if (nr >= 0 and nr < R and
                        nc >= 0 and nc < C and
                        board[nr][nc] != -1):
                        temp[nr][nc] += n
                        board[i][j] -= n

    for i in range(R):
        for j in range(C):
            board[i][j] += temp[i][j]

def circulation():
    i = cleaner - 1
    while i > 0:
        board[i][0] = board[i - 1][0]
        i -= 1
    i = 0
    while i < C - 1:
        board[0][i] = board[0][i + 1]
        i += 1
    i = 0
    while i < cleaner:
        board[i][C - 1] = board[i + 1][C - 1]
        i += 1
    i = C - 1
    while i > 1:
        board[cleaner][i] = board[cleaner][i - 1]
        i -= 1
    board[cleaner][1] = 0

    i = cleaner + 2
    while i < R - 1:
        board[i][0] = board[i + 1][0]
        i += 1
    i = 0
    while i < C - 1:
        board[R - 1][i] = board[R - 1][i + 1]
        i += 1
    i = R - 1
    while i > cleaner + 1:
        board[i][C - 1] = board[i - 1][C - 1]
        i -= 1
    i = C - 1
    while i > 1:
        board[cleaner + 1][i] = board[cleaner + 1][i - 1]
        i -= 1
    board[cleaner + 1][1] = 0

for i in range(R):
    board.append(list(map(int, input().strip().split())))
    if cleaner == 0 and board[i][0] == -1:
        cleaner = i

for _ in range(T):
    spread()
    circulation()

result = sum([sum(board[i]) for i in range(R)]) + 2

print(result)