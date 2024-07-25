#include <iostream>
#include <string>
#include <vector>

int N, M, S_len;	// S_len = 본문에서 찾을문자열 길이, M = 본문문자열 길이
std::string S;

std::vector<int> getPi(std::string str) {
	int j{ 0 };
	std::vector<int> pi(S_len, 0);
	for (int i = 1; i < S_len; i++) {
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[i] == str[j])
			pi[i] = ++j;
	}
	return pi;
}

int kmp(std::string temp_S) {
	int answer{ 0 };
	std::vector<int> pi = getPi(temp_S);
	int j{ 0 };

	for (int i = 0; i < M; i++) {
		while (j > 0 && S[i] != temp_S[j])
			j = pi[j - 1];
		if (S[i] == temp_S[j]) {
			if (j == S_len - 1) {
				answer++;
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return answer;
}

int main() {
	std::cin >> N >> M >> S;
	S_len = 2 * N + 1;

	std::string temp_S;
	for (int i = 0; i < S_len; i++) {
		if (i % 2) temp_S += 'O';
		else temp_S += 'I';
	}

	std::cout << kmp(temp_S);

}