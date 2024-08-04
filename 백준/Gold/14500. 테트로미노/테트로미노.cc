#include <iostream>

int N, M;
int arr[501][501];
int t_x[7][4] = { {0, 1, 2, 3}, {0, 1, 0, 1}, {0, 1, 1, 1}, {0, 0, 1, 2}, {0, 1, 1, 2}, {0, 0, 1, 1}, {0, 1, 2, 1} };
int t_y[7][4] = { {0, 0, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 2}, {0, 1, 1, 1}, {0, 0, 1, 1}, {0, 1, 1, 2}, {0, 0, 0, 1} };
// 순서대로 1자(가로), 정사각형, ㄱ자, 뒤집은 ㄱ자, ㄹ자, 뒤집은 ㄹ자, ㅗ자;

std::pair<bool, int> test(int y, int x, int num, int sum) {
	int i{ 0 };
	int nx{ 0 }, ny{ 0 };
	int temp{ 0 };
	for (int j = 0; j < 4; j++) { // 4번의 rotate를 위한 반복문
		temp = 0;
		for (i = 0; i < 4; i++) { // 4칸을 돌기위한 반복문
			switch (j) {
			case 0:
				// 원래
				nx = x + t_x[num][i];
				ny = y + t_y[num][i];
				break;
			case 1:
				// 180
				nx = x - t_x[num][i];
				ny = y - t_y[num][i];
				break;
			case 2:
				// 시계 90
				nx = x + t_y[num][i];
				ny = y - t_x[num][i];
				break;
			case 3:
				// 반시계 90
				nx = x - t_y[num][i];
				ny = y + t_x[num][i];
				break;
			}
			if (0 >= nx || nx > M || 0 >= ny || ny > N) {
				// 범위 밖
				break;
			}

			temp += arr[ny][nx];
		}
		if (temp > sum) sum = temp;
	}
	return { true, sum };
}

int main() {
	std::cin >> N >> M;
	// 세로N 가로M
	int result{ 0 };

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			std::cin >> arr[i][j];
		}
	}

	bool boolean;
	int sum{ 0 };
	int i{ 0 }, j{ 0 };

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			for (int k = 0; k < 7; k++) { // 7개의 도형을 위한 반복문
				std::pair<bool, int> temp = test(i, j, k, sum);
				boolean = temp.first;
				sum = temp.second;
				if (boolean == true && sum > result) result = sum;
			}
		}
	}
	std::cout << result;
}