#include <iostream>

int main() {
	int lst[42]{ 0 };
	for (int i = 0; i < 10; ++i) {
		int j;
		std::cin >> j;
		lst[j % 42] = 1;
	}
	int res{ 0 };
	for (int i = 0; i < 42; ++i) {
		if (lst[i] != 0) res++;
	}
	std::cout << res;
}