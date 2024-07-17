#include <iostream>
#include <vector>
#include <queue>

int map[1002][1002]{ 0 };
int ans[1002][1002];
std::queue<std::pair<std::pair<int, int>, int>> q;

void bfs(int n, int m) {

	q.push({ { n, m }, 0 });

	
	while (!q.empty()) {
		int temp_n = q.front().first.first;
		int temp_m = q.front().first.second;
		int count = q.front().second;
		q.pop();

		if (map[temp_n][temp_m] == 0) {
			continue;
		}
		if (ans[temp_n][temp_m] == -1) {
			ans[temp_n][temp_m] = count;
		}
		else if (count < ans[temp_n][temp_m]) {
			ans[temp_n][temp_m] = count;
		}

		// visited
		map[temp_n][temp_m] = 0;

		q.push({ {temp_n + 1, temp_m}, count + 1 });
		q.push({ {temp_n, temp_m + 1}, count + 1 });
		q.push({ {temp_n - 1, temp_m}, count + 1 });
		q.push({ {temp_n, temp_m - 1}, count + 1 });
	}
	

}

int main() {

	// ans 배열 -1로 초기화
	for (int i = 0; i < 1002; i++) {
		std::fill(ans[i], ans[i] + 1002, -1);
	}

	int n, m;	// n세로, m가로;
	int ob_n, ob_m;

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 2) {
				ob_n = i; ob_m = j;
			}
			else if (map[i][j] == 0) {
				ans[i][j] = 0;
			}
		}
	}

	bfs(ob_n, ob_m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cout << ans[i][j] << " ";
		}
		std::cout << "\n";
	}
}