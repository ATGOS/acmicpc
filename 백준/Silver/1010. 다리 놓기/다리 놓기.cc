#include <iostream>

int arr[31][31]{ 0 }; // nCr 저장

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	for (int i = 1; i < 31; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == j || j == 0) arr[i][j] = 1;
			else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	int T;
	int N, M;

	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> N >> M;
		if (N == M) {
			std::cout << 1 << "\n";
			continue;
		}
		std::cout << arr[M][N] << "\n";

	}
}