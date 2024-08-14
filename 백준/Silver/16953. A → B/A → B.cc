#include <iostream>
#include <climits>
#include <queue>

int answer{ INT_MAX };
long long int A, B;
std::queue<std::pair<long long int, std::pair<int, int>>> q; // 해당숫자, count, 연산종류

void bfs() {
	q.push({ A, {1, 0} });
	q.push({ A, {1, 1} });
	while (!q.empty()) {
		long long int t_A = q.front().first;
		int count = q.front().second.first;
		int k = q.front().second.second;
		q.pop();
		if (t_A == B && count < answer) {
			answer = count;
			continue;
		}
		if (t_A > B) {
			continue;
		}
		if (k == 0) {
			// 2를 곱하는 연산.
			q.push({ 2 * t_A, {count + 1, 0} });
			q.push({ 2 * t_A, {count + 1, 1} });
			continue;
		}
		if (k == 1) {
			// 1을 수의 가장 오른쪽에 추가하는 연산.
			q.push({ 10 * t_A + 1, {count + 1, 0} });
			q.push({ 10 * t_A + 1, {count + 1, 1} });
			continue;
		}
	}

}

int main() {

	std::cin >> A >> B;


	bfs();
	if (answer == INT_MAX) std::cout << -1;
	else std::cout << answer;
}