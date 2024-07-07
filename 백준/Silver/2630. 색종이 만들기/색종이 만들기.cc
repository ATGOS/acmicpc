#include <iostream>

int n;
int white = 0, blue = 0;
int arr[129][129]{};

void sep(int x, int y, int scale) {
	int temp = arr[y][x];
	for (int i = 0; i < scale; i++) {
		for (int j = 0; j < scale; j++) {
			if (temp != arr[i + y][j + x]) {
				scale /= 2;
				sep(x, y, scale);
				sep(x + scale, y, scale);
				sep(x, y + scale, scale);
				sep(x + scale, y + scale, scale);
				return;
			}
		}
	}

	if (temp == 1) {
		blue++;
	}
	else {
		white++;
	}

}

int main() {

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> arr[i][j];
		}
	}

	sep(0, 0, n);
	std::cout << white << "\n" << blue;

	return 0;

}