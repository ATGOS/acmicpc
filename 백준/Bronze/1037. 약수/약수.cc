#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> v;
	int temp;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		v.push_back(temp);
	}
	std::sort(v.begin(), v.end());
	std::cout << v[0] * v[v.size() - 1];
}