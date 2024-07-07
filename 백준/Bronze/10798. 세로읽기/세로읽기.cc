#include <iostream>
#include <string>

int main() {

	std::string a[5];
	int b[5]{};

	for (int i = 0; i < 5; i++) {
		std::cin >> a[i];
		b[i] = a[i].length();
	}

	int largest = b[0];
	for (int i = 1; i < 5; i++) {
		largest = std::max(largest, b[i]);
	}

	for (int i = 0; i < largest; i++) {
		for(int j = 0; j < 5; j++) {
			if (b[j] > i) {
				std::cout << a[j][i];
			}
		}
	}

	return 0;

}