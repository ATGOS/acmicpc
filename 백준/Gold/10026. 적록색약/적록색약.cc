#include <iostream>
char arr[101][101];
int N;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int count{ 0 };
bool visited[101][101]{ false };

void dfs(int x, int y, int counting) {
	char color;
	color = arr[x][y];
	if (counting == 1) count++;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		char next_color = arr[nx][ny];
		if (next_color == color && 0 < nx && nx <= N && 0 < ny && ny <= N) {
			if (visited[nx][ny] == false) {
				dfs(nx, ny, counting + 1);
			}
		}
	}
}

int main() {
	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j] == false) dfs(i, j, 1);
		}
	}
	std::cout << count << "\n";


	for (int i = 1; i <= N; i++) {
		std::fill(&visited[i][1], &visited[i][N + 1], false);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 'R') arr[i][j] = 'G';
		}
	}
	count = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j] == false) dfs(i, j, 1);
		}
	}
	std::cout << count;
}