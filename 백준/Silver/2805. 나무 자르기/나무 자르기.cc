#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long m;
    std::cin >> n >> m;

    
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());

    int left = 0;
    int right = v[n - 1];

    while (left <= right) {
        int middle = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            if (v[i] > middle) {
                sum += v[i] - middle;
            }
        }

        if (sum < m) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }

    std::cout << right;
}