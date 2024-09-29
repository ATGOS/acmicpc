#include <iostream>
bool arr[20'000'001]{ 0 }; // arr[0] -> -10'000'000, 

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N;
	std::cin >> N;
	int k;
	while (N--) {
		std::cin >> k;
		arr[k + 10'000'000] = true;
	}
	int M;
	std::cin >> M;
	while (M--) {
		std::cin >> k;
		if (arr[k + 10'000'000] == true) {
			std::cout << "1 ";
		}
		else {
			std::cout << "0 ";
		}
	}
}