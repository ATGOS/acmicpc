#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

/*
* M 가로 N 세로 H 높이
* 0 안익은
* 1 익은
* -1 들어있지 않은
*/

int M, N, H;
std::vector<std::vector<std::vector<int>>> tomato; // H, N, M
std::queue<std::tuple<int, int, int>> q; // (z, x, y)
int directions[6][3] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };

bool isValid(int x, int y, int z) { // N M H 순서
    return (x >= 0 && x < N && y >= 0 && y < M && z >= 0 && z < H);
}

int bfs() {
    int days = 0;

    while (!q.empty()) {
        int size = q.size();
        bool ripened = false;

        for (int i = 0; i < size; ++i) {
            int z = std::get<0>(q.front());
            int x = std::get<1>(q.front());
            int y = std::get<2>(q.front());
            q.pop();

            for (int j = 0; j < 6; ++j) {
                int nz = z + directions[j][0];
                int nx = x + directions[j][1];
                int ny = y + directions[j][2];

                if (isValid(nx, ny, nz) && tomato[nz][nx][ny] == 0) {
                    tomato[nz][nx][ny] = 1;
                    q.push(std::make_tuple(nz, nx, ny));
                    ripened = true;
                }
            }
        }

        if (ripened) {
            ++days;
        }
    }

    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (tomato[k][i][j] == 0) {
                    return -1; // 아직 익지 않은 토마토가 남아있는 경우
                }
            }
        }
    }

    return days;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> M >> N >> H;
    tomato.resize(H, std::vector<std::vector<int>>(N, std::vector<int>(M)));
    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                std::cin >> tomato[k][i][j];
                if (tomato[k][i][j] == 1) {
                    q.push(std::make_tuple(k, i, j));
                }
            }
        }
    }

    int result = bfs();
    std::cout << result;
}