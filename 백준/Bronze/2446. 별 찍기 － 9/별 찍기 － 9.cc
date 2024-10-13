#include <iostream>

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			std::cout << " ";
		}
		for (int k = 1; 2 * (N - i) > k; ++k) {
			std::cout << "*";
		}
		std::cout << "\n";
	}

	for (int i = N - 2; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			std::cout << " ";
		}
		for (int k = 1; k < 2 * (N - i); k++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}

}