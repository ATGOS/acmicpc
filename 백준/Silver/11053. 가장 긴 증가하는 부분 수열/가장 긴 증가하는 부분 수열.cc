#include <iostream>

int main() {
	int N;
	std::cin >> N;
	int arr[1000];
	int dp[1000]{ 0 };
	dp[0] = 1;
	int ans{ 0 };

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	

	for (int i = 1; i <= N; i++) {
		int temp{ 0 };
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
		ans = std::max(dp[i], ans);
	}
	std::cout << ans;
}