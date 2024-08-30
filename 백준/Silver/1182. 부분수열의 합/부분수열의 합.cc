#include <iostream>
#include <algorithm>

int N, S;
int num_list[20];
int answer{ 0 };

void dfs(int num, int sum) {
	num++;
	if (num == N && sum == S) {
		answer++;
		return;
	}
	else if (num == N) {
		return;
	}
	dfs(num, sum + num_list[num]); // 더한 것
	dfs(num, sum); // 안 더한 것
}

int main() {

	std::cin >> N >> S;

	for (int i = 0; i < N; i++) {
		std::cin >> num_list[i];
	}
	
	if (S == 0) answer--;

	dfs(-1, 0);

	std::cout << answer;
	
}