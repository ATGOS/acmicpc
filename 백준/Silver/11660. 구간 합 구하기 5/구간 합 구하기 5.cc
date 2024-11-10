#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;

	std::cin >> N >> M;

	int** arr = new int* [N];
	for (int i = 0; i < N;  ++i) {
		arr[i] = new int[N];
	}

	int** sum = new int* [N];
	for (int i = 0; i < N; ++i) {
		sum[i] = new int[N];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> arr[i][j];
		}
	}

	sum[0][0] = arr[0][0];

	for (int i = 1; i < N; ++i) {
		sum[0][i] = sum[0][i - 1] + arr[0][i];
		sum[i][0] = sum[i - 1][0] + arr[i][0];
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			sum[i][j] = arr[i][j] + sum[i - 1][j] 
				+ sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	while (M--) {
		int x1, y1, x2, y2, s = 0;
		std::cin >> x1 >> y1 >> x2 >> y2;

		s += sum[x2 - 1][y2 - 1];
		if (y1 != 1) s -= sum[x2 - 1][y1 - 2];
		if (x1 != 1)s -= sum[x1 - 2][y2 - 1];
		if (x1 != 1 && y1 != 1)s += sum[x1 - 2][y1 - 2];

		std::cout << s << "\n";
	}
}