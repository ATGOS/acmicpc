#include <iostream>
#include <queue>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N;
	std::cin >> N;
	int answer{ 0 };
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	int stack_size;
	while (N--) {
		std::cin >> stack_size;
		pq.push(stack_size);
	}
	while (pq.size() != 1) {
		int temp1{ pq.top() };
		pq.pop();
		int temp2{ pq.top() };
		pq.pop();
		pq.push(temp1 + temp2);
		answer += (temp1 + temp2);
	}
	std::cout << answer;
}