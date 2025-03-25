#include <iostream>
#include <map>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::map<std::string, int> m;
	m["ChongChong"] = 1;

	int N;
	std::cin >> N;

	int res{ 0 };

	for (int i = 0; i < N; ++i) {
		std::string s1, s2;
		std::cin >> s1 >> s2;

		if (m[s1] != 0 || m[s2] != 0) {
			m[s1] = 1; m[s2] = 1;
		}
	}

	for (auto iter : m) {
		if (iter.second == 1) res++;
	}

	std::cout << res;
}