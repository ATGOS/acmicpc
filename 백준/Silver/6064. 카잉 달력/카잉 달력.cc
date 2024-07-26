#include <iostream>
using namespace std;

// 확장 유클리드 알고리즘을 사용하여 GCD와 x, y를 계산
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

// 중국인의 나머지 정리를 사용하여 해를 구함
int chineseRemainderTheorem(int M, int N, int x, int y) {
    int a = (x - 1) % M;
    int b = (y - 1) % N;
    int x1, y1;
    int g = gcdExtended(M, N, x1, y1);

    if ((b - a) % g != 0) return -1; // 해가 없는 경우

    int lcm = M / g * N; // M과 N의 최소 공배수
    int result = (a + (x1 * ((b - a) / g) % (N / g)) * M) % lcm;

    if (result < 0) result += lcm;
    return result + 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << chineseRemainderTheorem(M, N, x, y) << endl;
    }
    return 0;
}
