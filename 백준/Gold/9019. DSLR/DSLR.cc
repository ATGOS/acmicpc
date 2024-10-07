#include <iostream>
#include <queue>
#include <string>
#include <cstring>

int A, B;
std::string answer;
char command[4] = { 'D', 'S', 'L', 'R' };

int process(int n, int com_num) {
	switch (command[com_num]) {
	case 'D':
		return (2 * n > 9999) ? 2 * n % 10000 : 2 * n;
	case 'S':
		return (n == 0) ? 9999 : n - 1;
	case 'L':
		return (n % 1000) * 10 + n / 1000;
	case 'R':
		return (n % 10) * 1000 + (n / 10);
	}
}

void bfs() {
	std::queue<std::pair<int, std::string> > q;	// bfs용 queue, { { 숫자n, 명령 종류 }, 명령어 string }
	bool visited[10'000]{ 0, };

	q.push({ A, "" });
	visited[A] = 1;

	while (!q.empty()) {
		int n{ q.front().first };
		std::string temp{ q.front().second };
		q.pop();

		if (n == B) {
			answer = temp;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int next_n = process(n, i);

			if (!visited[next_n]) {
				visited[next_n] = 1;
				q.push({ next_n, temp + command[i] });
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;
	std::cin >> T;

	while (T--) {

		std::cin >> A >> B;
		bfs();
		std::cout << answer << "\n";
	}
}