import sys

class Qnode:
    def __init__(self, data) -> None:
        self.data = data
        self.next: 'Qnode' = None

class Queue:
    def __init__(self) -> None:
        self.__front: Qnode = None
        self.__rear: Qnode = None

    def empty(self) -> bool:
        return self.__front is None and self.__rear is None
    
    def front(self) -> any:
        if self.empty():
            return None
        else:
            return self.__front.data
    
    def enqueue(self, data) -> None:
        new_node = Qnode(data)
        if self.empty():
            self.__front = self.__rear = new_node
        else:
            self.__rear.next = new_node
            self.__rear = new_node

    def dequeue(self) -> None:
        if self.empty():
            pass
        elif self.__front is self.__rear:
            self.__front = self.__rear = None
        else:
            self.__front = self.__front.next

    def pop(self) -> any:
        result = self.front()
        self.dequeue()
        return result

DXY = [(0, 1), (1, 0), (-1, 0), (0, -1)]

board: list
n: int
m: int

def bfs():
    visited = [[0]*(m+2) for _ in range(n+2)]
    visited[1][1] = 1
    queue = Queue()
    queue.enqueue((1, 1))

    while(not queue.empty()):
        x, y = queue.pop()

        if x == n and y == m:
            return visited[x][y]
        
        for dx, dy in DXY:
            nx = x + dx
            ny = y + dy
            if board[nx][ny] == 1 and visited[nx][ny] == 0:
                queue.enqueue((nx, ny))
                visited[nx][ny] = visited[x][y] + 1

    return -1

input = sys.stdin.readline

n, m = map(int, input().strip().split())

board = [[0]*(m+2) for _ in range(n+2)]

for i in range(1, n+1):
    line = input().strip()
    for j in range(1, m+1):
        board[i][j] = int(line[j - 1])

print(bfs())
