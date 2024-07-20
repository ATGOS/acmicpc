#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> fruits(N);
    for (int i = 0; i < N; i++) {
        std::cin >> fruits[i];
    }

    int max_length = 0;
    int left = 0;
    std::unordered_map<int, int> count_map;

    for (int right = 0; right < N; right++) {
        count_map[fruits[right]]++;

        while (count_map.size() > 2) {
            count_map[fruits[left]]--;
            if (count_map[fruits[left]] == 0) {
                count_map.erase(fruits[left]);
            }
            left++;
        }

        max_length = std::max(max_length, right - left + 1);
    }

    std::cout << max_length;
}