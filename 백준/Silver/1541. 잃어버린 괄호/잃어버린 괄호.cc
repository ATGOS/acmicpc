#include <iostream>
#include <string>

int main() {
	std::string ipt;
	int ans{ 0 };
	std::string prev{ "" };

	std::cin >> ipt;
	ipt += "+";
	bool ifmin = false;

	for (char i : ipt) {
		if (i == '-') {
			// - 등장시
			if (ifmin) {
				// - 등장이 O
				ans -= std::stoi(prev);
			}
			else {
				// - 등장이 X
				ans += std::stoi(prev);
				ifmin = true;
			}
			prev = "";
		}
		else if (i == '+') {
			// + 등장시
			if (ifmin) {
				// - 등장이 O
				ans -= std::stoi(prev);
			}
			else {
				// - 등장이 X
				ans += std::stoi(prev);
			}
			prev = "";
		}
		else {
			// 숫자등장시
			prev += i;
		}

	}
	std::cout << ans;
}