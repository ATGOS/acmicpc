#include <iostream>
#include <algorithm>

int N, S;
int num_list[20];
int answer{ 0 };

void dfs(int num, int sum) {

	if (num == N - 1 && sum == S) {
		answer++;
		return;
	}
	else if (num == N - 1) {
		return;
	}
	dfs(num + 1, sum + num_list[num + 1]); // 더한 것
	dfs(num + 1, sum); // 안 더한 것
}

int main() {

	std::cin >> N >> S;

	for (int i = 0; i < N; i++) {
		std::cin >> num_list[i];
	}
	
	//std::sort(num_list, num_list + 20);

	if (S == 0) answer--;

	dfs(0, num_list[0]);
	dfs(0, 0);

	std::cout << answer;
	
}