#include <iostream>
int main() {
	int A, B, V;
	std::cin >> A >> B >> V;
	int one_day{ A - B };
	int temp{ (V - A) / one_day * one_day };
	int answer{ (V - A) / one_day };
	while (true) {
		if (temp + A >= V) {
			answer++;
			break;
		}
		else {
			temp += one_day;
			answer++;
		}
	}

	std::cout << answer;
}