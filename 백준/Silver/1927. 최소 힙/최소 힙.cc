#include <iostream>
#include <queue>

int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	std::cin >> N;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	int x;
	while (N--) {
		std::cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				std::cout << 0;
			}
			else {
				std::cout << pq.top();
				pq.pop();
			}
			std::cout << "\n";
		}
		else {
			pq.push(x);
		}
	}
}