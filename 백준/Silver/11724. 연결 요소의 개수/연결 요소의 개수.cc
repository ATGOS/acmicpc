#include <iostream>

int N{ 0 }, M{ 0 };
int arr[1001][1001]{ 0 };
int visited[1001]{ 0 };
int connected_comp{ 0 };

void dfs(int node, int num) {
	if (visited[node] == 0) {
		visited[node] = 1;
		for (int j = 1; j <= N; j++) {
			if (arr[node][j] == 1 && visited[j] == 0 && j != node) {
				dfs(j, num + 1);
			}
		}
		if (num == 1) {
			connected_comp++;
		}
	}
}

int main() {
	std::cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		dfs(i, 1);
	}
	std::cout << connected_comp;

}