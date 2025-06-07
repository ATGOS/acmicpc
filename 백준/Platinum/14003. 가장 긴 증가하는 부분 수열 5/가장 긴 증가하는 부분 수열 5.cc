#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;	// 수열의 크기
	std::cin >> N;
	int ans;	// 최대부분수열의 길이

	std::vector<int> arr(N + 1, 0);	// 수열 저장
	arr[0] = -1'000'000'001;	// 1 based index를 위한 0번째 초기화

	std::vector<int> dp(N + 1, 0); 
	// 해당 인덱스를 마지막 값으로 하는 최대 부분수열의 길이
	// ex) dp[4] = 2 (4번째 요소를 마지막 값으로 하는 최대부분수열의 길이가 2)
	dp[0] = 0; 

	std::vector<int> dp2(N + 1, 0);
	// 최대부분수열의 길이에 대한 마지막 값의 최솟값
	// ex) dp2[3] = 7 (길이가 3인 최대부분수열들중 마지막 값의 최솟값이 7)
	dp2[0] = -1'000'000'001;
	int last_index_dp2 = 0;
	// dp2의 마지막 인덱스, 최대부분수열의 길이가 늘어날 수록 늘려야 함.

	for (int i = 0; i < N; ++i) {
		std::cin >> arr[i];	// 수열 입력
		
		if (dp2[last_index_dp2] < arr[i]) {
			last_index_dp2++;
			dp[i] = last_index_dp2;
			dp2[last_index_dp2] = arr[i];	// 현재 수열의 값이 마지막 값보다 크면 길이를 늘려야 함
		}
		else {
			// 현재 수열의 값이 마지막 값보다 작거나 같으면
			// dp2에서 현재 수열의 값보다 크거나 같은 가장 작은 값을 찾아서
			// 해당 인덱스에 현재 수열의 값을 넣어야 함
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
			dp2[left] = arr[i];	// 현재 수열의 값이 마지막 값보다 작거나 같으면 해당 인덱스에 값을 넣음
		}
	}
	ans = last_index_dp2;

	std::vector<int> result(ans, 0);
	// 역추적으로 최대부분수열 구하기
	for(int i = N; i >= 0; --i) {
		if (dp[i] == last_index_dp2) {
			result[last_index_dp2 - 1] = arr[i];	// 현재 인덱스가 최대부분수열의 마지막 값이면 해당 값을 저장
			last_index_dp2--;
		}
	}
	std::cout << ans << "\n";	// 최대 부분수열의 길이 출력
	for (int i : result) std::cout << i << " ";
	/*
	for (int i = 0; i < N; ++i) {
		std::cout << dp[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i <= ans; ++i) {
		std::cout << dp2[i] << " ";
	}
	std::cout << "\n";
	*/
}