#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

int N, answer{ 0 };
int arr[20][20]{ 0 };	// main arr
std::vector<std::pair<int, std::pair<int, int>>> v;	// <거리, <x좌표, y좌표>>
int visited[20][20]{ 0 };// visited arr, 1이면 visit함
int num[7]{ 0 };		// 1, 2, 3, 4, 5, 6 의 개수 저장
int shark_x, shark_y;	// 좌표는 맨 왼쪽 위를 0, 0이라 한다
int shark_size{ 2 }, count_eaten_fish{ 0 };	// 상어 크기, 먹은 물고기
int dir_x[4] = { -1, 0, 0, 1 };
int dir_y[4] = { 0, -1, 1, 0 };
std::queue<std::pair<int, std::pair<int, int>>> q;	// bfs용, <거리, <x좌포, y좌표>>

// 더 이상 먹을 수 있는 물고기가 없을 때 false 반환
bool is_done() {
	for (int i = 1; i < (shark_size > 6 ? 7 : shark_size); i++) {
		if (num[i] != 0) return true;
	}
	return false;
}

void bfs() {

	while (!q.empty()) {
		int count = q.front().first;
		int start_x = q.front().second.first;
		int start_y = q.front().second.second;
		q.pop();

		if (arr[start_y][start_x] != 0 && arr[start_y][start_x] < shark_size) {
			// 자신보다 작은 물고기가 있을 때, 먹음
			v.push_back({ count, { start_x, start_y } });	// 먹을 수 있는 칸이면 거리와 좌표 저장
		}

		for (int i = 0; i < 4; i++) {
			// 좌상하우 순서로 탐색
			int new_x{ start_x + dir_x[i] }, new_y{ start_y + dir_y[i] };
			if (arr[new_y][new_x] <= shark_size
				&& visited[new_y][new_x] == 0
				&& 0 <= new_x && new_x < N
				&& 0 <= new_y && new_y < N) {
				// 범위 안에 있고, 지나갈 수 있는 칸이며(상어 크기와 같거나 0) 방문했던 칸이 아닐 때

				visited[new_y][new_x] = 1;
				q.push({ count + 1, { new_x, new_y } });
			}
		}
	}

}

int main() {
	std::cin >> N;
	int temp;
	// N * N 입력 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> temp;
			if (temp != 0) {
				if (temp == 9) {
					shark_x = j;
					shark_y = i;
				}
				else {
					num[temp]++;
				}
			}
			arr[i][j] = temp;
		}
	}
	arr[shark_y][shark_x] = 0;

	while (is_done()) {
		// std::cout << shark_size << " " << shark_x << " " << shark_y << "\n";

		// visited, v, q 초기화
		v.clear();
		std::memset(visited, 0, sizeof(visited));
		std::queue<std::pair<int, std::pair<int, int>>> empty;
		std::swap(q, empty);
		/*
		* v  <거리, <x좌표, y좌표>>
		* q  <x좌표, y좌표>
		*/

		q.push({ 0, { shark_x, shark_y } });
		bfs();

		/*
		for (std::pair<int, std::pair<int, int>> temp : v) {
			std::cout << "거리: " << temp.first << " x: " << temp.second.first << " y: " << temp.second.second << "\n";
		}
		*/
		if (v.empty()) break;
		// 거리가 같다면 가장 위(y가 최소), 여러 마리라면 가장 왼쪽(x)기준으로 정렬
		std::sort(v.begin(), v.end()
			, [](const std::pair<int, std::pair<int, int>>& a
				, const std::pair<int, std::pair<int, int>>& b) {
					if (a.first != b.first) {
						return a.first < b.first;
					}
					else if (a.second.second != b.second.second) {
						return a.second.second < b.second.second;
					}
					else {
						return a.second.first < b.second.first;
					}
			});

		int dis = v.front().first;
		shark_x = v.front().second.first;
		shark_y = v.front().second.second;

		// 먹은 칸의 숫자에 대한 num 감소
		num[arr[shark_y][shark_x]] -= 1;
		// 먹은 칸 빈칸으로 만듦
		arr[shark_y][shark_x] = 0;
		// 먹은 숫자 증가 후 아기 상어 크기가 커질 수 있는지 검사
		count_eaten_fish++;
		if (count_eaten_fish == shark_size) {
			count_eaten_fish = 0;
			shark_size++;
		}

		answer += dis;
		// std::cout << "num" << num[1] << " " << num[2] << " " << num[3] << " " << num[4] << " " << num[5] << " " << num[6] << "\n";
	}
	std::cout << answer;

}