#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::vector<std::pair<int, int>> vec;	// 무게w, 가치v
	int* arr = new int[K + 1] {0};

	for (int i = 0; i < N; ++i) {
		int w, v;
		std::cin >> w >> v;
		vec.push_back({ w, v });
	}


	for (int i = 0; i < N; ++i) {
		for (int j = K; j >= 0; --j) {
			if (j >= vec[i].first)
				arr[j] = std::max(arr[j], arr[j - vec[i].first] + vec[i].second);
		}
	}

	std::cout << arr[K];
}