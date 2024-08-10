#include <iostream>

int tree[500][500];
int n;

int main() {
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			std::cin >> tree[i][j];
		}
	}

	for (int i = 1; i < n; i++) { // int i = 0 일 때는 제외
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				// 양 끝일 때는 위의 수가 한개뿐.
				tree[i][0] += tree[i - 1][0];
				continue;
			}
			else if (j == i) {
				tree[i][j] += tree[i - 1][j - 1];
				continue;
			}

			int temp{ std::max(tree[i - 1][j - 1], tree[i - 1][j]) };
			tree[i][j] += temp;

		}
	}

	int answer{ 0 };
	for (int i = 0; i < n; i++) {
		answer = std::max(tree[n - 1][i], answer);
	}
	std::cout << answer;
}