#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
const int INF = 100'000'000;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	std::vector<std::vector<int>> graph(N + 1, std::vector<int>(N + 1, INF));
	std::vector<int> distance(N + 1, INF);
	std::vector<bool> visited(N + 1, false);

	for (int i = 0; i < M; ++i) {
		int a, b, cost;
		std::cin >> a >> b >> cost;
		graph[a][b] = std::min(graph[a][b], cost);  // 같은 노선 여러 번 나올 수 있음
	}

	int Start, End;
	std::cin >> Start >> End;

	distance[Start] = 0;

	for (int i = 1; i <= N; ++i) {
		int minDist = INF;
		int minIndex = -1;

		// 방문 안 한 노드 중 가장 가까운 노드 찾기
		for (int j = 1; j <= N; ++j) {
			if (!visited[j] && distance[j] < minDist) {
				minDist = distance[j];
				minIndex = j;
			}
		}

		if (minIndex == -1) break;	// 모두 방문했으면 break

		visited[minIndex] = true;

		// 인접 노드 거리 갱신
		for (int j = 1; j <= N; ++j) {
			if (graph[minIndex][j] != INF && distance[j] > distance[minIndex] + graph[minIndex][j]) {
				distance[j] = distance[minIndex] + graph[minIndex][j];
			}
		}
	}

	std::cout << distance[End];
}
