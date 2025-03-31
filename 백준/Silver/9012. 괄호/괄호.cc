#include <iostream>
#include <string>

bool f(std::string s) {	// (, )
	int l{ 0 }, r{ 0 };
	for (char i : s) {
		if (i == '(')l++;
		if (i == ')')r++;
		if (l < r) return false;
	}
	if (l != r) return false;
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	std::cin >> t;
	std::string s;
	for (int i = 0; i < t; ++i) {
		std::cin >> s;

		std::cout << (f(s) ? "YES" : "NO") << "\n";

	}
}