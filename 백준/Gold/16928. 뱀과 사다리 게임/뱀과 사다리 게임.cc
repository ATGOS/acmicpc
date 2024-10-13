#include <iostream>
#include <vector>
#include <queue>
// BFS

std::queue<std::pair<int, int>> q;	// { 칸, count } 해당 칸까지 오는데에 몇 번의 주사위를 굴렸는지
bool visited[100]{ 0, };	// 1번 칸부터 99번 칸까지 방문 여부 arr
int move[101]{ 0 };	// 각 칸에서 뱀이든 사다리든 이동하는 위치 ex) 87 -> 13  move[87] = 13 / 0이면 없음
int answer{ 0 };

void bfs() {
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty()) {
		int space{ q.front().first };
		int count{ q.front().second };
		q.pop();

		if (move[space] != 0) {
			space = move[space];
			visited[move[space]] = true;
		}

		if (space >= 94) {
			answer = count + 1;
			return;
		}

		for (int i : arr) {
			int new_space{ space + i };
			if (move[new_space] == 0 && visited[new_space] == 0) {
				q.push({ new_space, count + 1 });
			}
			else if (visited[new_space] == 0) {
				q.push({ move[new_space], count + 1 });
				visited[move[new_space]] = true;
			}
			visited[new_space] = true;
		}
		
	}
}

int main() {
	int ladder_N, snake_M;
	std::cin >> ladder_N >> snake_M;

	for (int i = 0; i < ladder_N; i++) {
		int x, y;	// x < y	x -> y
		std::cin >> x >> y;
		move[x] = y;
	}
	for (int i = 0; i < snake_M; i++) {
		int u, v;	// u > v	u -> v
		std::cin >> u >> v;
		move[u] = v;
	}
	bfs();

	std::cout << answer;

}