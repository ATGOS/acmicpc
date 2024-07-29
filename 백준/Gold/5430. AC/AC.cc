#include <iostream>
#include <string>
#include <deque>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T, n;
	std::string P, arr;
	std::deque<int> deq;

	std::cin >> T;

	while (T--) {
		bool ifreversed{ false };
		deq.clear();
		int i;

		std::cin >> P;
		std::cin >> n;
		std::cin >> arr;

		// [1,2,3,4] 를 덱에 넣는 작업
		std::string temp{""};
		for (i = 1; i < arr.size() - 1; i++) {
			if (isdigit(arr[i])) {
				// [1,2,3,4] 에서 숫자일 때
				temp += arr[i];
			}
			else {
				// , 일때
				deq.push_back(std::stoi(temp));
				temp = "";
			}
			
		}
		if(temp != "") deq.push_back(std::stoi(temp));

		// 명령어 P 실행
		for (i = 0; i < P.length(); i++) {
			if (P[i] == 'R') {
				// R
				ifreversed = !ifreversed;
			} else{
				// D
				if (deq.size() == 0) break;
				if (ifreversed == false) deq.pop_front();
				else deq.pop_back();
			}
		}

		if (i != P.length()) {
			// error
			std::cout << "error\n";
		}
		else {
			std::cout << '[';
			if (ifreversed == false) {
				for (i = 0; i < (int)deq.size() - 1; i++) {
					std::cout << deq[i] << ",";
				}
				if (deq.size() != 0) std::cout << deq[i];
			}
			else {
				for (i = (int)deq.size() - 1; i > 0; i--) {
					std::cout << deq[i] << ",";
				}
				if (deq.size() != 0) std::cout << deq[0];
			}
			std::cout << "]\n";
		}


	}
}