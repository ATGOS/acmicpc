#include <iostream>

int N, M, answer{ 0 };
std::string S, temp_S;

// str.substr(시작위치, 길이) 길이생략시 마지막문자까지
// 이때 길이 = 2N+1

int main() {
	std::cin >> N >> M >> S;

	for (int i = 0; i < 2 * N + 1; i++) {
		if (i % 2) temp_S += 'O';
		else temp_S += 'I';
	}


	for (int i = 0; i <= M - (2 * N + 1); i++) {
		if (S.substr(i, 2 * N + 1) == temp_S) answer++;
	}

	std::cout << answer;
}