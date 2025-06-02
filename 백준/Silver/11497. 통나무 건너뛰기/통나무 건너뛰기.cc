#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;
	std::cin >> T;

	while (T--) {
		int N;
		std::cin >> N;
		std::vector<int> v(N + 1);
		for (int i = 1; i <= N; ++i) std::cin >> v[i];
		std::sort(v.begin(), v.end());

		int m{ 0 };
		if (N % 2 == 0) {
			// 짝수개
			for (int i = 1; i < N - 1; i += 2) {
				m = std::max(m, v[i + 2] - v[i]);
			}

			for (int i = 2; i < N; i += 2) {
				m = std::max(m, v[i + 2] - v[i]);
			}
		}
		else {
			// 홀수개
			for (int i = 1; i < N; i += 2) {
				m = std::max(m, v[i + 2] - v[i]);
			}

			for (int i = 2; i < N - 1; i += 2) {
				m = std::max(m, v[i + 2] - v[i]);
			}
		}
		m = std::max(m, v[N] - v[N - 1]);
		m = std::max(m, v[2] - v[1]);
		std::cout << m << "\n";
	}
}