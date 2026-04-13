#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int maze[MAX_N + 2][MAX_M + 2];
int dp[MAX_N + 2][MAX_M + 2];

int N, M;
char line[MAX_M + 1];

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	dp[1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == N && y == M) {
			return dp[x][y];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (maze[nx][ny] == 1 && dp[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				dp[nx][ny] = dp[x][y] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> line;
		for (int j = 1; j <= M; j++) {
			maze[i][j] = line[j - 1] & 1;
		}
	}

	int result = bfs();

	cout << result << endl;

	return 0;
}
