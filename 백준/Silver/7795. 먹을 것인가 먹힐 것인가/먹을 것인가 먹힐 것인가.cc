#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;
	std::cin >> T;

	while (T--) {
		int nA, nB;
		int ans{ 0 };
		std::cin >> nA >> nB;
		std::vector<int> vA(nA), vB(nB);
		for (int i = 0; i < nA; ++i) std::cin >> vA[i];
		for (int i = 0; i < nB; ++i) std::cin >> vB[i];
		std::sort(vA.begin(), vA.end());
		std::sort(vB.begin(), vB.end());

		int pB{ 0 };
		for (int i = 0; i < nA; ++i) {
			while (pB < nB && vA[i] > vB[pB]) {
				pB++;
			}
			ans += pB;
		}
		std::cout << ans << "\n";
	}
}