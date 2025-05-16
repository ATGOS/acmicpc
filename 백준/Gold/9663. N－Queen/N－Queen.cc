#include <iostream>
#include <vector>

int N;
int answer{ 0 };
std::vector<std::vector<bool>> chess(16, std::vector<bool>(16, false));	// 빈칸:false, 퀸:true

bool check_queen(int y, int x) {	
	// chess[y][x]에 설치된 퀸의 공격 범위에 무언가 존재하는지 체크
	// 존재하면 false, 설치 가능하면 true
	
	// 세로
	for (int i = y; i >= 1; --i) {
		if (chess[i][x] == true) return false;
	}

	// 왼쪽 위 대각선
	for (int i = y, j = x; i >= 1 && j >= 1; --i, --j) {
		if (chess[i][j]) return false;
	}

	// 오른쪽 위 대각선
	for (int i = y, j = x; i >= 1 && j <= N; --i, ++j) {
		if (chess[i][j]) return false;
	}

	// 가로는 필요 없음

	return true;
}

void placing_queen(int l) {	// l : L번째 줄(1~15), 

	if (l == N + 1) {
		answer++;
		return;
	}

	for (int i = 1; i <= N; ++i) {
		if (check_queen(l, i) == true) {
			chess[l][i] = true;
			placing_queen(l + 1);
			chess[l][i] = false;
		}
	}

}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;

	placing_queen(1);

	std::cout << answer;
}