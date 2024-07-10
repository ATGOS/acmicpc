#include <iostream>
#include <queue>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::priority_queue<int, std::vector<int>> q;
	
	int N;
	std::cin >> N;

	int a;
	for (int i = 0; i < N; i++) {
		std::cin >> a;
		if (a == 0) {
			if (q.empty()) {
				std::cout << 0 << "\n";
			}
			else {
				std::cout << q.top() << "\n";
				q.pop();
			}
		}
		else {
			q.push(a);
		}
	}
}