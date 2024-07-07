#include <iostream>
#include <algorithm>

int main()
{

	int n;
	std::cin >> n;

	int arr[1000][3];
	int dp[1001][3];
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	int minn{};
	if (n == 2) {
		int tmparr[6] = {
			arr[0][0] + arr[1][1],
			arr[0][0] + arr[1][2],
			arr[0][1] + arr[1][0],
			arr[0][1] + arr[1][2],
			arr[0][2] + arr[1][0],
			arr[0][2] + arr[1][1]
		};
		std::cout << *std::min_element(tmparr, tmparr + (sizeof(tmparr) / sizeof(int)));
	}
	else {
		for (int i = 0; i < n; i++) {
			dp[i + 1][0] = std::min(dp[i][1], dp[i][2]) + arr[i][0];
			dp[i + 1][1] = std::min(dp[i][0], dp[i][2]) + arr[i][1];
			dp[i + 1][2] = std::min(dp[i][0], dp[i][1]) + arr[i][2];
		}
		std::cout << std::min(std::min(dp[n][0], dp[n][1]), dp[n][2]);
	}

}