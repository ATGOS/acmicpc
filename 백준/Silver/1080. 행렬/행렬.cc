#include <iostream>

int x[9] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
int y[9] = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	int ans{ 0 };

	bool** A = new bool*[N];
	for (int i = 0; i < N; ++i) A[i] = new bool[M];
	bool** B = new bool* [N];
	for (int i = 0; i < N; ++i) B[i] = new bool[M];

	std::string s;
	for (int i = 0; i < N; ++i) {
		std::cin >> s;
		for (int j = 0; j < M; ++j) {
			A[i][j] = (s[j] == '1');
		}
	}
	for (int i = 0; i < N; ++i) {
		std::cin >> s;
		for (int j = 0; j < M; ++j) {
			B[i][j] = (s[j] == '1');
		}
	}

	if (N < 3 || M < 3) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j] != B[i][j]) {
					std::cout << -1;
					return 0;
				}
			}
		}
		std::cout << 0;
	}
	else {
		for (int i = 0; i <= N - 3; ++i) {
			for (int j = 0; j <= M - 3; ++j) {
				if (A[i][j] != B[i][j]) {
					ans++;
					for (int k = 0; k < 9; ++k) {
						A[i + y[k]][j + x[k]] = !A[i + y[k]][j + x[k]];
					}
				}
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j] != B[i][j]) {
					std::cout << -1;
					return 0;
				}
			}
		}
		std::cout << ans;
	}
}