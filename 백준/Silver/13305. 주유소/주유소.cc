#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	std::cin >> N;
	long long ans{ 0 };

	std::vector<long long> road_length(N - 1);
	std::vector<long long> oil_price(N);
	for (int i = 0; i < N - 1; ++i) std::cin >> road_length[i];
	for (int i = 0; i < N; ++i) std::cin >> oil_price[i];

	long long cur = oil_price[0];
	for (int i = 0; i < N - 1; ++i) {
		if (cur > oil_price[i]) cur = oil_price[i];
		ans += cur * road_length[i];
	}
	std::cout << ans;
}