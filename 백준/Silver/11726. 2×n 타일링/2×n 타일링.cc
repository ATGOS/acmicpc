#include <iostream>

int main() {
	int n;
	int a1 = 1, a2 = 2;
	int ans;
	std::cin >> n;
	for (int i = 3; i <= n; ++i) {
		ans = (a1 + a2) % 10'007;
		a1 = a2;
		a2 = ans;
	}
	if (n == 1) std::cout << 1;
	else if (n == 2) std::cout << 2;
	else std::cout << ans % 10'007;
}