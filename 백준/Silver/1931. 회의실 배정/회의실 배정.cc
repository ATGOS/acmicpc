#include <iostream>
#include <vector>
#include <algorithm>

int N;
int a, b;
int answer{ 0 };

bool cmp(std::pair<int, int>a, std::pair<int, int>b) {
	// main의 b-a 가 작은 것 기준으로 오름차순 정렬을 위한 함수
	return a.second - a.first < b.second - b.first;
}

bool cmp2(std::pair<int, int>a, std::pair<int, int>b) {
	// 끝나는 시간이 가장 빠른 순서의 역순대로, 즉 (main의 b 기준) 내림차순 정렬을 위한 함수
	if (a.second == b.second) {
		return a.first > b.first;
	}
	else {
		return a.second > b.second;
	}
}

int main() {
	std::vector<std::pair<int, int>> p;

	std::cin >> N;

	int finish_time{ 0 };

	for (int i = 0; i < N; i++) {
		std::cin >> a >> b;
		// a는 시작시간 b는 종료시간
		p.push_back(std::make_pair(a, b));
	}
	sort(p.begin(), p.end(), cmp2);

	for (int i = 0; i < N; i++) {
		if (finish_time <= p.back().first) {
			finish_time = p.back().second;
			answer++;
		}
		p.pop_back();
	}

	std::cout << answer;
}