#include <iostream>
#include <map>
#include <queue>
#include <vector>


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;

	while (T--) {
		int k;
		std::cin >> k;
		char c;
		int n;
		std::map<int, int> m;
		std::priority_queue<int> pq_max;	// 최대 힙
		std::priority_queue<int, std::vector<int>, std::greater<int>> pq_min;	// 최소 힙
		while (k--) {
			std::cin >> c >> n;
			
			if (c == 'I') {
				// 삽입
				m[n]++;
				pq_min.push(n);
				pq_max.push(n);
			}
			else {
				// 삭제
				if (n == 1) {
					re_n1:
					// 최댓값 삭제
					if (pq_max.empty()) continue;		// Q가 비어있을 때, 무시
					int max_top = pq_max.top();
					if (m[max_top] == 0) {
						// 이미 pq_min에서 없어진 값일 때
						pq_max.pop();
						goto re_n1;
					}
					m[max_top]--;
					pq_max.pop();
				}
				else {
					re_n0:
					// 최솟값 삭제
					if (pq_min.empty()) continue;	// Q가 비어있을 때, 무시
					int min_top = pq_min.top();
					if (m[min_top] == 0) {
						// 이미 pq_max에서 없어진 값일 때
						pq_min.pop();
						goto re_n0;
					}
					m[min_top]--;
					pq_min.pop();
				}

			}
		}

		// 연산 후 남은 것들 다시 계산
		bool if_empty = true;
		last_max:
		// 최댓값 삭제
		if (!pq_max.empty()) {
			int max_top = pq_max.top();
			if (m[max_top] == 0) {
				// 이미 pq_min에서 없어진 값일 때
				pq_max.pop();
				goto last_max;
			}
			if_empty = false;
			std::cout << max_top << " ";
		}

		if(if_empty) std::cout << "EMPTY" << "\n";		// Q가 비어있을 때, EMPTY
		
		last_min:
		// 최댓값 삭제
		if (!pq_min.empty()) {
			int min_top = pq_min.top();
			if (m[min_top] == 0) {
				// 이미 pq_max에서 없어진 값일 때
				pq_min.pop();
				goto last_min;
			}
			std::cout << min_top << "\n";
		}

	}
}