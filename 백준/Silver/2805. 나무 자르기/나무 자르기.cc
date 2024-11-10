#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long m;
    std::cin >> n >> m;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + n);

    int left = 0;
    int right = arr[n - 1];

    while (left <= right) {
        int middle = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            if (arr[i] > middle) {
                sum += arr[i] - middle;
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