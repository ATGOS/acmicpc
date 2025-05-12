#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	std::cin >> N;
	std::vector<int> v(N + 5);
	v[1] = 0; v[2] = 1; v[3] = 1;
	for (int i = 4; i <= N; ++i) {
		v[i] = v[i - 1] + 1;
		if (!(i % 2)) v[i] = std::min(v[i], v[i / 2] + 1);
		if (!(i % 3)) v[i] = std::min(v[i], v[i / 3] + 1);
	}
	std::cout << v[N];
}