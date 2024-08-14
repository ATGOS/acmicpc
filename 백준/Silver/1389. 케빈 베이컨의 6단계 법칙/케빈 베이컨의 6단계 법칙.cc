#include <iostream>

int N, M;
int arr[101][101]{ 0 };

int main() {
	std::cin >> N >> M;

	for (int i = 1; i < 101; i++) {
		std::fill(&arr[i][1], &arr[i][1] + 100, 100'000'000);
	}

	int a, b;
	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j] = std::min(arr[i][k] + arr[k][j], arr[i][j]);
			}
		}
	}

	int answer1{ 100'000'000 }, answer2, temp;
	for (int i = 1; i <= N; i++) {
		temp = 0;
		for (int j = 1; j <= N; j++) {
			temp += arr[i][j];
		}
		if (temp < answer1) {
			answer1 = temp;
			answer2 = i;
		}
	}
	std::cout << answer2;

}