#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	std::sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << '\n';
	}

	delete[] arr;

	return 0;

}