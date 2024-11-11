#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

bool comp(int a, int b) {	
	a = abs(a);
	b = abs(b);

	if (a < b) return true;
	else return false;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; ++i) {
		std::cin >> arr[i];
	}

	std::sort(arr, arr + N, comp);

	int ans = INT_MAX;
	int ans_arr[2];

	for (int i = 0; i < N - 1; ++i) {
		if (abs(arr[i] + arr[i + 1]) < ans) {
			ans = abs(arr[i] + arr[i + 1]);
			ans_arr[0] = arr[i];
			ans_arr[1] = arr[i + 1];
		}
	}
	std::sort(ans_arr, ans_arr + 2);

	std::cout << ans_arr[0] << " " << ans_arr[1];

}