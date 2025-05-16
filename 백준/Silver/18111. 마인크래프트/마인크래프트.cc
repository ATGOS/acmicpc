#include <iostream>
#include <vector>

int N, M, B;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M >> B;

	std::vector<std::vector<int>> minecraft(N, std::vector<int>(M));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			std::cin >> minecraft[i][j];

	int time{ 10'0000'0000 }; int h{ 0 };

	for (int i = 0; i <= 256; ++i) {
		int temp_b{ B }; int temp_time{ 0 };
		for (int n = 0; n < N; ++n) {
			for (int m = 0; m < M; ++m) {
				if (minecraft[n][m] > i) {
					// 블럭을 깨야할 때
					temp_time += (2 * (minecraft[n][m] - i));
				}
				else {
					// 블럭을 설치하거나, 아무것도 할 필요가 없을 때
					temp_time += (i - minecraft[n][m]);
				}
				// 인벤토리에 블럭 추가 or 제거
				temp_b += (minecraft[n][m] - i);
			}
		}
		if (temp_b < 0) break;	// 인벤에 블럭이 음수 개일 때
		if (temp_time <= time) {
			// 이 경우의 시간값이 최소일 때.
			// 기준 높이(i)를 증가시키며 검사하므로 뒤에 것이 언제나 더 크다
			time = temp_time;
			h = i;
		}
	}
	std::cout << time << " " << h;
}