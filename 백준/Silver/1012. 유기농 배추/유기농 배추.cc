#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int x[4] = { 1, -1, 0, 0 };	// 동 서 남 북
int y[4] = { 0, 0, -1, 1 };

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	for (int l = 0; l < T; ++l) {

		int M, N, K;	// 가로, 세로, 배추 개수
		std::cin >> M >> N >> K;

		// 2차원 node
		std::vector<std::vector<int>> arr(N, std::vector<int>(M, 0));

		// 2차원 visited
		std::vector<std::vector<int>> visited(N, std::vector<int>(M, 0));

		// bfs용 queue
		std::queue<std::pair<int, int>> q; // [y][x]

		// input
		for (int i = 0; i < K; ++i) {
			int a, b;
			std::cin >> a >> b;
			arr[b][a] = 1;
		}

		int count{ 0 };
		// bfs
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (arr[i][j] == 1 && visited[i][j] != 1) {
					count++;
					q.push({ i, j });
					visited[i][j] = 1;
					while (!q.empty()) {
						std::pair<int, int> p = q.front();
						q.pop();
						for (int k = 0; k < 4; ++k) {
							int nx = p.second + x[k];
							int ny = p.first + y[k];
							if (0 <= ny && ny < N
								&& 0 <= nx && nx < M
								&& arr[ny][nx] == 1 && visited[ny][nx] != 1) {
								visited[ny][nx] = 1;
								q.push({ ny, nx });
							}
						}
					}
				}
			}
		}

		std::cout << count << "\n";


	}
}