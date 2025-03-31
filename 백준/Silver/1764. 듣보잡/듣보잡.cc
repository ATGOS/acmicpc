#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<std::string> v;
	int N, M;
	std::cin >> N >> M;
	std::map<std::string, int> m;

	std::string s;
	for (int i = 0; i < N; ++i) {
		std::cin >> s;
		m[s]++;
	}
	for (int i = 0; i < M; ++i) {
		std::cin >> s;
		if (m[s] == 1) v.push_back(s);
	}

	std::sort(v.begin(), v.end());

	std::cout << v.size() << "\n";
	for (std::string str : v) std::cout << str << "\n";
}