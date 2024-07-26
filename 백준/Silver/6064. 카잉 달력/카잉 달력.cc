#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// 확장 유클리드 알고리즘을 이용하여 GCD와 x, y를 계산
int gcdExtended(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

// 중국인의 나머지 정리를 이용하여 해를 구함
int chineseRemainderTheorem(int num1, int rem1, int num2, int rem2) {
    int x, y;
    int gcd = gcdExtended(num1, num2, x, y);
    if ((rem2 - rem1) % gcd != 0) return -1; // 해가 없는 경우
    int lcm = num1 / gcd * num2;
    x = (x * (rem2 - rem1) / gcd) % (num2 / gcd);
    int result = (rem1 + x * num1) % lcm;
    if (result < 0) result += lcm;
    return result;
}

int findK(int M, int N, int x, int y) {
    x--; // 0-based index로 변환
    y--;
    int result = chineseRemainderTheorem(M, x, N, y);
    if (result == -1) return -1;
    return result + 1; // 1-based index로 반환
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << findK(M, N, x, y) << endl;
    }
    return 0;
}
