#include <iostream>

int main() {
	int N;
	std::cin >> N;

	for (int i = N; i > 0; --i) {
		for (int j = 0; j < N - i; ++j) {
			std::cout << " ";
		}
		for (int k = 2 * i - 1; k > 0; --k) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
}