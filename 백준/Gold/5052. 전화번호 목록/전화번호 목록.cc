#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

/*
일관성: 한 번호가 다른 번호의 접두어인 경우 X

트리 인덱스 (1부터 시작) 실제숫자 0~9 => 인덱스 1~10
10k + (숫자 + 1) = 10k + 숫자인덱스
*/

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
				// std::cout << "index: " << index << "num: " << num << "\n";
			}
			if (coh == false) break;
			for (int i = 1; i <= 10; ++i) m[10 * index + i] = 11;
		}

		std::cout << (coh ? "YES" : "NO") << "\n";
	}

}