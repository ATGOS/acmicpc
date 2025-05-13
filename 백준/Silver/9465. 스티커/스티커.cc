#include <iostream>
#include <vector>
/*

3번째 줄 위에것까지의 최대 : 
"2번째 줄이 아래인것까지의 최대 + 3번째줄위" 또는
"1번째 줄이 아래인것까지의 최대 + 3번째줄위"

3번째 줄 아래것까지의 최대 :
"2번째 줄이 위인것까지의 최대 + 3번째줄 아래" 또는
"1번째 줄이 위인것까지의 최대 + 3번째줄 아래"

*/

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> v(2, std::vector<int>(n));
		std::vector<std::vector<int>> dp(2, std::vector<int>(n));
		for (int i = 0; i < n; ++i) std::cin >> v[0][i];
		for (int i = 0; i < n; ++i) std::cin >> v[1][i];

		if (n == 1) {
			std::cout << std::max(v[0][0], v[1][0]) << "\n";
			continue;
		}

		dp[0][0] = v[0][0]; dp[1][0] = v[1][0];
		dp[0][1] = v[1][0] + v[0][1];
		dp[1][1] = v[0][0] + v[1][1];

		for (int i = 2; i < n; ++i) {
			dp[0][i] = std::max(dp[1][i - 1], dp[1][i - 2]) + v[0][i];
			dp[1][i] = std::max(dp[0][i - 1], dp[0][i - 2]) + v[1][i];
		}
		std::cout << std::max(dp[0][n - 1], dp[1][n - 1]) << "\n";
	}
}