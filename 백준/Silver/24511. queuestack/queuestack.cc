#include <iostream>
#include <vector>
#include <queue>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	int* lst = new int[N];	//  큐라면 0, 스택이라면 1;
	int* qs = new int[N];

	for (int i = 0; i < N; ++i) std::cin >> lst[i];
	for (int i = 0; i < N; ++i) std::cin >> qs[i];

	std::queue<int> q;

	for (int i = N - 1; i >= 0; --i) {
		if (lst[i] == 0) q.push(qs[i]);
	}
	
	int M;
	std::cin >> M;
	int* elems = new int[M];
	for (int i = 0; i < M; ++i) std::cin >> elems[i];

	// 큐라면 안에 있던 것이, 스택이라면 그대로 다시 나옴;
	for (int j = 0; j < M; ++j) {
		int elem = elems[j];
		q.push(elem);
		elem = q.front();
		q.pop();
		std::cout << elem << " ";
	}

	delete[] lst;
	delete[] elems;
}