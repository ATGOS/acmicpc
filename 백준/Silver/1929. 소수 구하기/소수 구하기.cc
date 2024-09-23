#include <iostream>

int main() {
	int M, N;
	std::cin >> M >> N;
	bool arr[1'000'001]{ 0 }; // 0이면 소수인 것
	arr[1] = 1;
	for (int i = 2; i * i < N + 1; i++) {
		if (arr[i] == 1) continue;
		for (int j = 2; i * j <= N; j++) {
			arr[i * j] = 1; // 
		}
	}
	for (int i = M; i <= N; i++) {
		if (arr[i] == 0) std::cout << i << "\n";
	}
}