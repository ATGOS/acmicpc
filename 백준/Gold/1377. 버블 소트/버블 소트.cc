#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> vec;
	std::pair<int, int> p;
	for (int i = 0; i < N; i++) {
		std::cin >> p.first;
		p.second = i;
		vec.push_back(p);
	}

	std::sort(vec.begin(), vec.end());

	int answer{ 0 };
	for (int i = 0; i < N; i++) {
		if (answer < vec[i].second - i) {
			answer = vec[i].second - i;
		}
	}
	std::cout << answer + 1;
}