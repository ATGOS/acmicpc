#include <iostream>
#include <deque>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::deque<int> dq;
	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		int m, x;
		std::cin >> m;
		switch (m) {
		case 1:
			std::cin >> x;
			dq.push_front(x);
			break;
		case 2:
			std::cin >> x;
			dq.push_back(x);
			break;
		case 3:
			if (!dq.empty()) {
				std::cout << dq.front() << "\n";
				dq.pop_front();
			}
			else {
				std::cout << "-1" << "\n";
			}
			break;
		case 4:
			if (!dq.empty()) {
				std::cout << dq.back() << "\n";
				dq.pop_back();
			}
			else {
				std::cout << "-1" << "\n";
			}
			break;
		case 5:
			std::cout << dq.size() << "\n";
			break;
		case 6:
			std::cout << dq.empty() << "\n";
			break;
		case 7:
			if (!dq.empty()) {
				std::cout << dq.front() << "\n";
			}
			else {
				std::cout << "-1" << "\n";
			}
			break;
		case 8:
			if (!dq.empty()) {
				std::cout << dq.back() << "\n";
			}
			else {
				std::cout << "-1" << "\n";
			}
			break;
		}
	}
}