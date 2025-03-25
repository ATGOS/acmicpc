#include <iostream>
#include <map>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::map<std::string, int> m;

	int N;
	std::cin >> N;

	int res{ 0 };

	for (int i = 0; i < N; ++i) {
		std::string s;
		std::cin >> s;
		if (s == "ENTER") m.erase(m.begin(), m.end());
		else if(m[s] == 0) {
			res++;
			m[s]++;
		}
	}

	std::cout << res;
}