#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	std::cin >> N;
	int ans;

	std::vector<int> arr(N + 1, 0);
	arr[0] = -1'000'000'001;

	std::vector<int> dp(N + 1, 0); 
	dp[0] = 0; 

	std::vector<int> dp2(N + 1, 0);
	dp2[0] = -1'000'000'001;
	int last_index_dp2 = 0;

	for (int i = 0; i < N; ++i) {
		std::cin >> arr[i];
		
		if (dp2[last_index_dp2] < arr[i]) {
			last_index_dp2++;
			dp[i] = last_index_dp2;
			dp2[last_index_dp2] = arr[i];
		}
		else {
			int left = 0, right = last_index_dp2;
			while (left < right) {
				int mid = (left + right) / 2;
				if (dp2[mid] < arr[i]) {
					left = mid + 1;
				} else {
					right = mid;
				}
			}
			dp[i] = left;
			dp2[left] = arr[i];
		}
	}
	ans = last_index_dp2;

	std::vector<int> result(ans, 0);
	for(int i = N; i >= 0; --i) {
		if (dp[i] == last_index_dp2) {
			result[last_index_dp2 - 1] = arr[i];
			last_index_dp2--;
		}
	}
	std::cout << ans << "\n";
	for (int i : result) std::cout << i << " ";

}