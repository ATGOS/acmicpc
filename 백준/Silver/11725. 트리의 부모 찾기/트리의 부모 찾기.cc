#include <iostream>
#include <vector>

std::vector<int> v[100'001];
int visited[100'001]{ 0 };
int arr[100'001]; // 각 노드의 부모노드를 저장하는 배열

void dfs(int start) {
	visited[start] = 1;
	for (int i : v[start]) {
		if (visited[i] == 1) continue;
		arr[i] = start;
		dfs(i);
	}
}

int main() {
	int N;
	std::cin >> N;

	int x, y;
	for (int i = 1; i < N; i++) {
		std::cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		std::cout << arr[i] << "\n";
	}
}