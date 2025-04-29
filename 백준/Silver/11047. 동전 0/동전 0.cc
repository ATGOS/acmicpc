#include <iostream>
#include <vector>

int main() {
	int N, K;
	int answer = 0;
	std::cin >> N >> K;
	std::vector<int> coin(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> coin[i];
	}
	int size = static_cast<int>(coin.size());
	for (int i = 1; i <= N; ++i) {
		int q = K / coin[size - i];
		K -= (coin[size - i] * q);
		answer += q;
	}
	std::cout << answer;
}