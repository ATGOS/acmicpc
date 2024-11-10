// 2차원 arr 포인터를 사용한 풀이.
#include <iostream>
#include <map>
// 맨위 왼쪽이 0, 0 맨위 오른쪽이 0, N

int mul[9][2] = { {0, 0}, {1, 0}, {2, 0}, {0, 1}, {1, 1}, {2, 1}, {0, 2}, {1, 2}, {2, 2} };
std::map<int, int> m;

void search(int** arr, int x, int y, int size) {
	int num = arr[y][x];
	if (size == 1) {
		m[num]++;
		return;
	}
	for (int i = y; i < y + size; ++i) {
		for (int j = x; j < x + size; ++j) {
			if (num != arr[i][j]) {
				size /= 3;
				for (int k = 0; k < 9; k++) {
					search(arr, x + mul[k][0] * size, y + mul[k][1] * size, size);
				}
				return;
			}
		}
	}
	m[num]++;
}


int main() {
	int N;
	std::cin >> N;

	int** arr = new int* [N];
	for (int i = 0; i < N; ++i) {
		arr[i] = new int[N];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> arr[i][j];
		}
	}

	search(arr, 0, 0, N);

	std::cout << m[-1] << "\n" << m[0] << "\n" << m[1];

	for (int i = 0; i < N; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}