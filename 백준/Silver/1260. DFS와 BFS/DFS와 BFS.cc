#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int N, M, StartNode;


void dfs(int node, int* visited, std::vector<std::vector<int>>& arr) {
	visited[node] = 1;
	std::cout << node << " ";
	for (int i = 1; i <= N; ++i) {
		if (arr[node][i] == 1 && visited[i] != 1) {
			dfs(i, visited, arr);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M >> StartNode;

	int* visited = new int[N + 1];

	// 2차원 node
	std::vector<std::vector<int>> arr(N + 1, std::vector<int>(N + 1, 0));

	// bfs용 queue
	std::queue<int> q; 

	// input
	for (int i = 0; i < M; ++i) {
		int a, b;
		std::cin >> a >> b;
		arr[a][b] = 1; arr[b][a] = 1;
	}

	// dfs
	dfs(StartNode, visited, arr);
	std::cout << "\n";

	// visited 초기화
	std::fill(visited + 1, visited + N + 1, 0);

	// bfs
	q.push(StartNode);
	visited[StartNode] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		std::cout << node << " ";
		for (int i = 1; i <= N; ++i)
			if (arr[node][i] == 1 && visited[i] != 1) {
				q.push(i);
				visited[i] = 1;
			}
	}
}