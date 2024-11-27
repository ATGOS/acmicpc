#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1'000'000'000

struct cmp {
	bool operator() (std::pair<int, int>& a, std::pair<int, int>& b) {
		if (a.second > b.second) return true;
		else return false;
	}
};

std::vector<std::pair<int, int>> v[1001];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> pq;	// { 목표 지점, 목표까지의 거리 }
int visited[1001];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::fill(visited, visited + 1001, INF);

	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		v[a].push_back({ b, c });	
		// v[n].second 는 n에서 v[n].first로 가는 비용
	}
	int start, end;
	std::cin >> start >> end;

	pq.push({ start, 0 });
	visited[start] = 0;

	while (!pq.empty()) {
		int now = pq.top().first;
		int dist = pq.top().second;
		pq.pop();

		if (visited[now] < dist) {
			continue;
		}
		for (int i = 0; i < v[now].size(); ++i) {
			int next = v[now][i].first;
			int next_dist = v[now][i].second + dist;
			if (visited[next] > next_dist) {
				visited[next] = next_dist;
				pq.push({ next, next_dist });
			}
		}
		
	}
	std::cout << visited[end];

}
