#include <iostream>
#include <vector>
#include <algorithm>

int N;
int arr[27][27]{ 0 };
std::vector<int> ans;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dfs(int i, int j) {	// i가 세로
	if (arr[i][j] == 0) return 0;
	arr[i][j] = 0;
	int rtn{ 0 };

	for (int k = 0; k < 4; k++) {
		rtn += dfs(i + dx[k], j + dy[k]);
	}
	return 1 + rtn;
}

int main() {
	std::cin >> N;

	std::string temp;
	for (int i = 1; i <= N; i++) {
		std::cin >> temp;
		for (int j = 1; j <= N; j++) {
			arr[i][j] = temp[j - 1] - '0';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1) {
				ans.push_back(dfs(i, j));
			}
		}
	}

	std::sort(ans.begin(), ans.end());

	std::cout << ans.size() << "\n";
	for (int i : ans) {
		std::cout << i << "\n";
	}

}