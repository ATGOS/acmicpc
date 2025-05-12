#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int stair;
	std::cin >> stair;
	std::vector<int> v(stair + 1);
	std::vector<int> dp(stair + 1, 0);
	for (int i = 1; i <= stair; ++i) {
		std::cin >> v[i];
	}

	if (stair == 1) {
		std::cout << v[1];
		return 0;
	}

	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	for (int i = 3; i <= stair; ++i) {
		dp[i] = v[i] + std::max(dp[i - 3] + v[i - 1], dp[i - 2]);
	}
	std::cout << dp[stair];
}