#include <stdio.h>
#include <stdlib.h>

typedef struct Qnode {
	int x;
	int y;
	struct Qnode* prev;
	struct Qnode* next;
} Qnode;

void enqueue(Qnode** q, int x, int y) {
	Qnode* newNode = (Qnode*)malloc(sizeof(Qnode));
	newNode->x = x;
	newNode->y = y;

	if (*q == NULL) {
		newNode->next = newNode;
		newNode->prev = newNode;
		*q = newNode;
	}
	else {
		newNode->prev = (*q)->prev;
		newNode->next = *q;
		newNode->prev->next = newNode;
		newNode->next->prev = newNode;
	}
}

void dequeue(Qnode** q) {
	Qnode* temp = *q;

	if (*q == (*q)->next) {
		*q = NULL;
	}
	else {
		(*q)->prev->next = (*q)->next;
		(*q)->next->prev = (*q)->prev;
		*q = (*q)->next;
	}

	free(temp);
}

#define MAX_N 100
#define MAX_M 100

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int board[MAX_N + 2][MAX_M + 2];
int visited[MAX_N + 2][MAX_M + 2];

int N, M;
char line[MAX_M + 1];

int bfs() {
	Qnode* head = NULL;
	enqueue(&head, 1, 1);
	visited[1][1] = 1;

	while (head != NULL) {
		int x = head->x;
		int y = head->y;
		dequeue(&head);

		if (x == N && y == M) {
			return visited[x][y];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (board[nx][ny] == 1 && visited[nx][ny] == 0) {
				enqueue(&head, nx, ny);
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%s", line);

		for (int j = 1; j <= M; j++) {
			board[i][j] = line[j - 1] & 1;
		}
	}

	int result = bfs();

	printf("%d\n", result);

	return 0;
}
