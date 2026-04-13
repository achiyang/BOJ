#include <iostream>
#include <vector>

class Robot {
public:
	Robot(int rows, int cols, int posY, int posX, int dir) : posY(posY), posX(posX), dir(dir){
		grid = std::vector<std::vector<int>>(rows, std::vector<int>(cols));
		// 그리드 입력 (0: 청소 가능, 1: 벽, 2: 청소된 구역)
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				std::cin >> grid[r][c];
			}
		}
	}

	int cleaning(void) {
		int count = 0;

		while (1) {
			if (grid[posY][posX] == 0) {
				grid[posY][posX] = 2; // 현재 상태를 청소 상태로 표시
				count++;
			}

			// 주변에 청소 가능한 구역이 없을 때, 뒤로 이동하거나 이동할 수 없을 경우 작업을 종료
			if (grid[posY + 1][posX] != 0 && grid[posY - 1][posX] != 0 &&
				grid[posY][posX + 1] != 0 && grid[posY][posX - 1] != 0) {
				if (grid[posY - dy[dir]][posX - dx[dir]] != 1) {
					posY -= dy[dir];
					posX -= dx[dir];
				}
				else {
					return count; // 작업을 종료하고 청소한 구역의 개수를 반환
				}
			}
			// 주변에 청소 가능한 구역이 있을 때, 반시계 방향으로 회전하고, 앞의 구역이 청소 가능할 경우 앞으로 위치를 옮김
			else {
				dir = (dir + 3) % 4;
				if (grid[posY + dy[dir]][posX + dx[dir]] == 0) {
					posY += dy[dir];
					posX += dx[dir];
				}
			}
		}
	}

private:
	int posY; // 현재 Y 위치
	int posX; // 현재 X 위치
	int dir;  // 현재 방향 (0: 북, 1: 동, 2: 남, 3: 서)
	std::vector<std::vector<int>> grid; // 2차원 그리드

	static const int dy[4]; // dy[dir]: Y방향 이동
	static const int dx[4]; // dx[dir]: X방향 이동
};

const int Robot::dy[4] = { -1, 0, 1, 0 };
const int Robot::dx[4] = { 0, 1, 0, -1 };

int main() {
	int r, c;

	std::cin >> r >> c; // 그리드의 행과 열 입력

	int Y, X, d;

	std::cin >> Y >> X >> d; // 로봇의 초기 위치 및 방향 입력

	Robot vacuum(r, c, Y, X, d); // Robot 클래스의 인스턴스 생성

	std::cout << vacuum.cleaning() << std::endl; // 청소 작업을 시작하고 청소한 구역의 개수를 출력

	return 0;
}