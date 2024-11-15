#include <iostream>

int main() {
	int N;
	std::cin >> N;
	int ans{ 0 };

	int i;
	for (i = N; i >= 0; i -= 2) {
		if (!(i % 5)) {
			ans += (i / 5);
			ans += (N - i) / 2;
			break;
		}
	}
	if (i <= 0 && ans == 0) {
		ans = -1;
	}

	std::cout << ans;
}