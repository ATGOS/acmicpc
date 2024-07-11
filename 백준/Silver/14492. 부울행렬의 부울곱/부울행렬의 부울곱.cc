#include <iostream>

int main() {
	int N;
	int a[301][301];
	int b[301][301];
	int answer{ 0 };

	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> a[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> b[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (a[i][k] == 1 && b[k][j] == 1) {
					answer++;
					break;
				}
			}
		}
	}
	std::cout << answer;
}