#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::string s;
	std::cin >> s;

	int weight{ 0 };
	int sum{ 0 };
	for (int i = 0; i < 13; ++i) {
		if (s[i] == '*') weight = (i % 2) * 2 + 1;
		else sum += (s[i] - 48) * ((i % 2) * 2 + 1);
	}
	for (int i = 0; i < 10; ++i) {
		if ((sum + i * weight) % 10 == 0) {
			std::cout << i;
			break;
		}
	}
}