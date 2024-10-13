#include <iostream>

int main() {
	int N;
	std::cin >> N;

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			std::cout << "*";
		}
		for (int k = 2 * (N - i); k > 0; --k) {
			std::cout << " ";
		}
		for (int j = 0; j < i; ++j) {
			std::cout << "*";
		}
		std::cout << "\n";
	}

	for (int i = N; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			std::cout << "*";
		}
		for (int k = 0; k < 2 * (N - i); k += 2) {
			std::cout << "  ";
		}
		for (int j = 0; j < i; ++j) {
			std::cout << "*";
		}
		std::cout << "\n";
	}

}