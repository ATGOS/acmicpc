#include <iostream>

int change{ 0 };

int main() {
	int N;
	int arr[101][101];

	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> arr[i][j];	// i -> j 인 간선
			if (arr[i][j] == 0) arr[i][j] = 100'000'000;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j] = std::min(arr[i][k] + arr[k][j], arr[i][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 100'000'000) std::cout << 0 << " ";
			else std::cout << 1 << " ";
		}
		std::cout << "\n";
	}
}