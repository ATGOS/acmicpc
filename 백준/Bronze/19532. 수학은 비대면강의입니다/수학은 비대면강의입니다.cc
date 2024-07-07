#include <iostream>

int main()
{
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    int y{ (a * f - c * d) / (a * e - b * d) };
    int x{};
    if (a != 0) {
        x = (c - b * y) / a;
    }
    else {
        x = (f - e * y) / d;
    }
    std::cout << x << " " << y;
}