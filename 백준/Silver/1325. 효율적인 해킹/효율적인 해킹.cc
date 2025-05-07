#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<int>> v(N + 1); // i가 걸리면 v[i][0~] 도 다 걸림
	int answer[10'001]{ 0 };

	while (M--) {
		int A, B;
		std::cin >> A >> B; // A가 B를 신뢰, 즉 B 해킹 -> A 해킹
		v[B].push_back(A);
	}


	for (int i = 1; i <= N; ++i) {
		bool visited[10'001]{ 0 };
		std::queue<int> q;

		q.push(i);
		visited[i] = 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			answer[i]++;

			for (int j = 0; j < v[cur].size(); ++j) {
				int next = v[cur][j];
				if(visited[next] == 0) {
					visited[next] = 1;
					q.push(next);
				}
			}
		}
	}

	int ans_max = *std::max_element(answer + 1, answer + N + 1);
	for (int i = 1; i <= N; i++) {
		if (answer[i] == ans_max) std::cout << i << " ";
	}
}