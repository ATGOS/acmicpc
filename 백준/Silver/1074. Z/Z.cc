#include <iostream>
#include <cmath>

int answer{};

void DC(int r, int c, int num) {
	if (num == 1) {
		return;
	}
	num = num / 2;
	// num = 반쪽길이
	if ((c < num) && (r < num)) {
		// 분할정복 : 왼쪽 위
		DC(r, c, num);
	}
	else if ((c >= num) && (r < num)) {
		// 분할정복 : 오른쪽 위
		answer += (int)std::pow(num, 2);
		DC(r, c - num,num);
	}
	else if ((c < num) && (r >= num)) {
		// 분할정복 : 왼쪽 아래
		answer += 2 * (int)std::pow(num, 2);
		DC(r - num, c, num);
	}
	else if ((c >= num) && (r >= num)) {
		// 분할정복 : 오른쪽 아래
		answer += 3 * (int)std::pow(num, 2);
		DC(r - num, c - num, num);
	}
}

int main() {
	int N;
	int r, c;
	std::cin >> N >> r >> c;

	DC(r, c, (int)std::pow(2, N));

	std::cout << answer;
}