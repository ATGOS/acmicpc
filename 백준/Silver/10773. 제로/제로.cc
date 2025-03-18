#include <iostream>
#include <stack>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int k;

	std::cin >> k;

	int m;
	std::stack<int> stk;
	for (int i = 0; i < k; i++) {
		std::cin >> m;
		if (m == 0) stk.pop();
		else stk.push(m);
	}
	
	int sum = 0;
	int s = static_cast<int>(stk.size());
	for (int i = 0; i < s; i++) {
		sum += stk.top();
		stk.pop();
	}
	std::cout << sum;
}