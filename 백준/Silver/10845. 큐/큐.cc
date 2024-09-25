#include <iostream>
#include <queue>
#include <string>

int main() {
	int N;
	std::cin >> N;
	std::string s;
	std::queue<int> q;

	while (N--) {
		std::cin >> s;
		if (s == "push") {
			int X;
			std::cin >> X;
			q.push(X);
		}
		else if (s == "pop") {
			if (q.empty()) std::cout << -1;
			else {
				std::cout << q.front();
				q.pop();
			}
			std::cout << "\n";
		}
		else if (s == "size") {
			std::cout << q.size() << "\n";
		}
		else if (s == "empty") {
			if (q.empty()) std::cout << 1;
			else std::cout << 0;
			std::cout << "\n";
		}
		else if (s == "front") {
			if (q.empty()) std::cout << -1;
			else std::cout << q.front();
			std::cout << "\n";
		}
		else if (s == "back") {
			if (q.empty()) std::cout << -1;
			else std::cout << q.back();
			std::cout << "\n";
		}
	}
}