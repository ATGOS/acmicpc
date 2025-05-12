#include <iostream>
#include <vector>
/*
가 : 왼쪽의 대각선 + 왼쪽의 가로	horizon
세 : 위쪽의 대각선 + 위쪽의 세로	vertic
대 : 왼쪽위의 가+세+대		diagon
*/
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> v(N + 1, std::vector<int>(N + 1));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> v[i][j];
		}
	}

	std::vector<std::vector<int>> hrz(N + 1, std::vector<int>(N + 1));	// 가로
	std::vector<std::vector<int>> vrt(N + 1, std::vector<int>(N + 1));	// 세로
	std::vector<std::vector<int>> dgn(N + 1, std::vector<int>(N + 1));	// 대각선

	for (int i = 1; i < N; ++i) {
		if (v[0][i] == 1) break;
		hrz[0][i] = 1;
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 2; j < N; ++j) {
			if (v[i][j] == 0) {
				hrz[i][j] = dgn[i][j - 1] + hrz[i][j - 1];
				vrt[i][j] = dgn[i - 1][j] + vrt[i - 1][j];
				if (v[i - 1][j] == 0 && v[i][j - 1] == 0) {
					dgn[i][j] = hrz[i - 1][j - 1] + vrt[i - 1][j - 1] + dgn[i - 1][j - 1];
				}
			}
		}
	}

	std::cout << hrz[N - 1][N - 1] + vrt[N - 1][N - 1] + dgn[N - 1][N - 1];
}