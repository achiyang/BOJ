#include <iostream>
#include <array>
#include <algorithm>

int tetromino[19][4][2] = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
    {{0, 0}, {-1, 0}, {-2, 0}, {-2, -1}},
    {{0, 0}, {0, -1}, {0, -2}, {1, -2}},
    {{0, 0}, {1, 0}, {2, 0}, {2, -1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {-1, 0}, {-2, 0}, {-2, 1}},
    {{0, 0}, {0, -1}, {0, -2}, {-1, -2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
    {{0, 0}, {1, 0}, {1, -1}, {2, -1}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {0, 2}},
    {{0, 0}, {-1, 0}, {-1, 1}, {-2, 0}},
    {{0, 0}, {0, -1}, {-1, -1}, {0, -2}},
    {{0, 0}, {1, 0}, {1, -1}, {2, 0}}
};

int N, M;

int getScore(int** board, int row, int col, int tetromino_index) {
    int score = 0;

    for (int i = 0; i < 4; i++) {
        int new_row = row + tetromino[tetromino_index][i][0];
        int new_col = col + tetromino[tetromino_index][i][1];
        if (new_row < 0 || new_row >= N || new_col < 0 || new_col >= M) {
            return 0;
        }
        score += board[new_row][new_col];
    }
    return score;
}

int main() {
    int max_score = 0;

    std::cin >> N >> M;

    int** board = new int* [N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[M];
        for (int j = 0; j < M; j++) {
            std::cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 19; k++) {
                int score = getScore(board, i, j, k);
                max_score = std::max(max_score, score);
            }
        }
    }

    std::cout << max_score << std::endl;

    for (int i = 0; i < N; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}