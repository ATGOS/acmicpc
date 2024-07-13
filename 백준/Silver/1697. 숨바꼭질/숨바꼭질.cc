#include <iostream>
#include <queue>

int current, ops;
int next1, next2, next3;

int minOperations(int start, int target) {
    if (start == target) return 0;

    bool visited[200'003]{ false };
    std::queue<std::pair<int, int>> q; // pair<int, int> : {현재 숫자, 연산 횟수}

    q.push({ start, 0 });
    visited[start] = true;

    while (!q.empty()) {
        current = q.front().first;
        ops = q.front().second;
        q.pop();

        next1 = current + 1;
        next2 = current - 1;
        next3 = current * 2;

        // 다음 연산이 마지막일 때
        if (next1 == target || next2 == target || next3 == target) {
            return ops + 1;
        }

        // 방문하지 않은 수일때, queue에 숫자 pair 추가
        if (visited[next1] == false) {
            q.push({ next1, ops + 1 });
            visited[next1] = true;
        }
        
        if (next2 >= 0 && visited[next2] == false) {
            q.push({ next2, ops + 1 });
            visited[next2] = true;
        }

        if (next3 <= 2 * target + 1 && visited[next3] == false) {
            q.push({ next3, ops + 1 });
            visited[next3] = true;
        }
    }
}

int main() {
    int N, K;
    std::cin >> N >> K;
    int result;

    if (N > K) {
        result = N - K;
    }
    else {
        result = minOperations(N, K);
    }

    std::cout << result;
}