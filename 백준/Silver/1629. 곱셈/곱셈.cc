#include <iostream>
#include <cmath>

using ull = unsigned long long;

ull C;

ull fpow(ull A, ull B) {
	if (B == 1) {
		// std::cout << A << " " << B << " " << A % C << "\n";
		return A % C;
	}
	else if (B % 2 == 1) {
		ull temp{ fpow(A, (B - 1) / 2) };
		// std::cout << A << " " << B << " " << ((ull)std::pow(fpow(A, (B - 1) / 2) % C, 2) * (A % C)) % C << "\n";
		return ((temp * temp) % C * (A % C)) % C;
	}
	else if (B % 2 == 0) {
		ull temp{ fpow(A, B / 2) };
		// std::cout << A << " " << B << " " << (ull)(std::pow(fpow(A, B / 2) % C, 2)) % C << "\n";
		return (temp * temp) % C;
	}
}

int main() {
	ull A, B;
	std::cin >> A >> B >> C;

	ull D{ 1 };

	if (A != 1) {
		D = fpow(A, B);
	}

	std::cout << D % C;
}