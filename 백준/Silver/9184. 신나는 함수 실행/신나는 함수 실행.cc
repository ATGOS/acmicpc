#include <iostream>

/*
* a, b, c 하나라도 0이하면		1
* a, b, c 하나라도 21이상이면	w(20, 20, 20)
* a < b < c 이면				w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
* else							w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
*/
int arr[21][21][21]{ 0 };

int w(int a, int b, int c) {
	if (a <= 0 or b <= 0 or c <= 0) return 1;
	if (a > 20 or b > 20 or c > 20) return w(20, 20, 20);
	if (a < b && b < c && arr[a][b][c] == 0) {
		int temp = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		arr[a][b][c] = temp;
		return temp;
	}
	else if (a < b && b < c) {
		return arr[a][b][c];
	}
	if (arr[a][b][c] == 0) {
		int temp = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		arr[a][b][c] = temp;
		return temp;
	}
	else {
		return arr[a][b][c];
	}
	
}

int main() {
	int a, b, c, answer;

	while (true) {
		std::cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		answer = w(a, b, c);

		std::cout << "w(" 
				<< a << ", "
				<< b << ", " 
				<< c << ") = " 
				<< answer << "\n";

	}
}