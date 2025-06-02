#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::cin >> n;

		std::map<long long, int> m;
		bool coh{ true };
		std::vector<std::string> v(n);

		for(int i = 0; i < n; ++i) {
			std::string s;
			std::cin >> v[i];
		}
		std::sort(v.begin(), v.end());
		for (int i = 0; i < n; ++i) {
			std::string s{ v[i] };
			long long index{ 0 };
			for (int i = 0; i < s.length(); ++i) {
				int num{ s[i] - '0' };
				index = 10 * index + num + 1;
				if (m[index] == 11) {
					coh = false;
					break;
				}
				m[index] = num;
			}
			if (coh == false) break;
			for (int i = 1; i <= 10; ++i) m[10 * index + i] = 11;
		}
		std::cout << (coh ? "YES" : "NO") << "\n";
	}
}