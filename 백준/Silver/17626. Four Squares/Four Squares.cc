#include <iostream>
#include <vector>

int main() {
	int n;
	int k{ 1 };

	std::cin >> n;
	
	int dp[50'001]{ 0 };


	for (int i = 1; i <= n; i++) {
		int minimum1 = 5;
		if (i % (k * k) == 0) {
			// i 자체로 제곱수일 때
			k++;
			dp[i] = 1;
			continue;
		}

		// j = 1부터 k 만큼 돌면서 dp[ i - j * j ] 의 최솟값 + 1을 dp에 지정
		for (int j = 1; j <= k; j++) {
			if (i > j * j && dp[i - j * j] < minimum1) {
				minimum1 = dp[i - j * j];
				dp[i] = minimum1 + 1;

			}
		}
	}

	std::cout << dp[n];
}