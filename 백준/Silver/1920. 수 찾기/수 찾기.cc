#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v;

bool bin_search(int start, int end, int b) {
	int mid = (start + end) / 2;
	if (end < start) return false;
	if (v[mid] == b) return true;
	if (mid == start || v[mid] < b) return bin_search(mid + 1, end, b);
	if (mid == end || v[mid] > b) return bin_search(0, mid - 1, b);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	while (N--) {
		int a;
		std::cin >> a;
		v.push_back(a);
	}
	std::sort(v.begin(), v.end());

	int M;
	std::cin >> M;
	while (M--) {
		int b;
		std::cin >> b;
		std::cout << bin_search(0, v.size() - 1, b) << "\n";
	}
}