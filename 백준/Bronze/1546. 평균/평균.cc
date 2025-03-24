#include <iostream>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;
	int* lst = new int[N];
	double new_avg{ 0 };
	for (int i = 0; i < N; ++i) {
		std::cin >> lst[i];
		new_avg += lst[i];
	}
	double max = *std::max_element(lst, lst + N);
	std::cout << (new_avg / max * 100) / N;
}