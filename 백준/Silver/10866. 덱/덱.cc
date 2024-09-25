#include <iostream>
#include <deque>
#include <string>

int main() {
	int N;
	std::cin >> N;
	std::string s;
	std::deque<int> d;

	while (N--) {
		std::cin >> s;
		if (s == "push_front") {
			int X;
			std::cin >> X;
			d.push_front(X);
		}
		else if (s == "push_back") {
			int X;
			std::cin >> X;
			d.push_back(X);
		}
		else if (s == "pop_front") {
			if (d.empty()) std::cout << -1;
			else {
				std::cout << d.front();
				d.pop_front();
			}
			std::cout << "\n";
		}
		else if (s == "pop_back") {
			if (d.empty()) std::cout << -1;
			else {
				std::cout << d.back();
				d.pop_back();
			}
			std::cout << "\n";
		}
		else if (s == "size") {
			std::cout << d.size() << "\n";
		}
		else if (s == "empty") {
			if (d.empty()) std::cout << 1;
			else std::cout << 0;
			std::cout << "\n";
		}
		else if (s == "front") {
			if (d.empty()) std::cout << -1;
			else std::cout << d.front();
			std::cout << "\n";
		}
		else if (s == "back") {
			if (d.empty()) std::cout << -1;
			else std::cout << d.back();
			std::cout << "\n";
		}
	}
}