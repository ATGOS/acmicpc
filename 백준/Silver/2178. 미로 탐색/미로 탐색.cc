#include <iostream>
#include <queue>

int N, M;
// N :세로 / M : 가로
int arr[102][102]{ 0 };
int visited[102][102]{ 0 };
std::queue<std::pair<int, int>> q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int tn, tm;
void bfs() {
	while (!q.empty()) {
		tn = q.front().first;
		tm = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			if (visited[tn + dx[k]][tm + dy[k]] == 0 && arr[tn + dx[k]][tm + dy[k]] != 0) {
				// 방문 안했고 막힌 길도 아니면
				arr[tn + dx[k]][tm + dy[k]] = arr[tn][tm] + 1;
				q.push({ tn + dx[k],tm + dy[k] });
				visited[tn + dx[k]][tm + dy[k]] = 1;
			}
		}

	}
}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < 102; i++) {
		std::fill(arr[i], arr[i] + 101, 0);
		std::fill(visited[i], visited[i] + 101, 0);
	}

	std::string temp;
	for (int i = 1; i <= N; i++) {
		std::cin >> temp;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = temp[j - 1] - '0';
		}
	}
	q.push({ 1, 1 });
	bfs();


	std::cout << arr[N][M];

}