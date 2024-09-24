#include <iostream>
#include <vector>
// sqrt(max) + 1 까지의 소수( 최대 1'000'001 )를 찾아 저장.
// min부터 max까지의 숫자에서 각 소수들의 배수를 체로 걸러 냄.

long long min, max;
int isprime_to_mil[1'000'003]{ 0 };
// sqrt(max) + 1까지의 소수를 찾기 위한 배열, 0이면 소수.
int answer_arr[1'000'001]{ 0 }; 
// 제곱ㄴㄴ수를 최종적으로 골라내기 위한 배열. 0이면 제곱ㄴㄴ수
// [0]번째 arr를 min이라 할 때, [1'000'000]번 째 arr는 min + 1,000,000 즉 max의 최대값.
std::vector<int> prime_list;
long long answer{ 0 };

int main() {
	isprime_to_mil[1] = 1;

	std::cin >> min >> max;

	for (long long i = 2; i * i <= max + 1; i++) {
		if (isprime_to_mil[i] == 1) continue;
		for (long long j = 2; i * j <= 1'000'002; j++) {
			isprime_to_mil[i * j] = 100;
		}
	}

	for (long long i = 2; i * i <= max + 1; i++) {
		if (isprime_to_mil[i] == 0) prime_list.push_back(i);
	}

	// for (long long i : prime_list) std::cout << i << "\n";

	for (long long i : prime_list) {
		i *= i;
		long long start{ (min / i) * i }; // min보다 큰 최소 배수.
		for (long long j = start; j <= max; j += i) {
			if(j >= min) answer_arr[j - min] = 1;
		}
	}
	for (int i = 0; i <= max - min; i++) {
		if (answer_arr[i] == 0) answer++;
	}
	std::cout << answer;
}