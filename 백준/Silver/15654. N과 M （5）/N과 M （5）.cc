#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
int arr[8];
int visited[8];
std::vector<int> v(8);

void dfs(int start, int count) {
	if (count == M) { // M개의 수열이 완성되었을 때, 그것을 출력
		for (int i = 0; i < M; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
		return;
	}

	// M개의 원소로 이루어진 수열 만들기
	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) continue;
		arr[count] = v[i];
		visited[i] = 1;
		dfs(i + 1, count + 1);
		visited[i] = 0;
	}
}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> v[i];
	}

	std::sort(v.begin(), v.begin() + N);

	dfs(0, 0);

}