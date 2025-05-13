#include <iostream>
#include <vector>
/*
0 << 가장 작은 "감소하는 수"
98'7654'3210 << 가장 큰 "감소하는 수"

0
...
9
1 0
2 0~1
3 0~2
4 0~3
...
96 97 98
3자리 부터는 백의 자리 숫자가 2이상이어야 함 -> 0 2C2 3C2 ... = 10C3
210 310 320 321
4자리 부터는 천의 자리 숫자가 3이상이어야 함 ->0 0 3C3 4C3 ... = 10C4
...
10자리 부터는 맨왼쪽 자리 숫자가 9이상이어야함 -> 0 0 ... 0 9C9 = 10C10

총합 = 2^10 - 1 = 1023
즉 0 ~ 1022

*/
std::vector<std::vector<int>> c(11, std::vector<int>(11));	// c[i][j] = iCj

void comb() {
	for (int i = 1; i <= 10; ++i) {
		c[i][i] = 1; c[i][1] = i; c[i][0] = 1;
	}

	for (int i = 2; i <= 10; ++i) {
		for (int j = 2; j < i; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
}

void dec_num(int n, int cnt) {
	// n : 자릿수, cnt : 남은 카운트
	// std::cout << "\n" << n << " " << cnt << "\n";
	for (int i = 1; i <= 10; ++i) {
		if (n == 1) {
			std::cout << cnt - 1;
			break;
		}
		if (cnt > c[i][n - 1]) cnt -= c[i][n - 1];
		else {
			std::cout << i;
			dec_num(n - 1, cnt);
			break;
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	std::cin >> N;
	N++;
	if (N > 1023) {
		std::cout << -1;
		return 0;
	}


	comb();

	for (int i = 1; i <= 10; ++i) {
		if (N > c[10][i]) N -= c[10][i];
		else {
			//std::cout << i << " " << N << "\n";
			dec_num(i, N);
			break;
		}
	}

}