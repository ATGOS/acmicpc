#include <iostream>

int N, M;
int arr[8]{ 0 };

void dfs(int start, int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
		return;
	}

	for (int i = start; i <= N; i++) {
		arr[count] = i;
		dfs(i + 1, count + 1);
	}
}

int main() {
	std::cin >> N >> M;
	dfs(1, 0);	
}