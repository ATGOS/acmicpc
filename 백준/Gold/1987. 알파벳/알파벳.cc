#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

int x[4] = {0, 0, 1, -1}; // 위 아래 오 왼
int y[4] = {1, -1, 0, 0};

int R, C; // 세로 가로
// A : 65 / Z : 90
bool visited[26]{ 0 };
std::vector<std::vector<char>> alp;
int result{ 0 };

void dfs(int i, int j, int res) {
    visited[alp[i][j] - 65] = 1;
    if (result < res) result = res;
    
    for (int m = 0; m < 4; ++m) {
        int nj = j + x[m];
        int ni = i + y[m];

        if (0 <= nj && nj < C && 0 <= ni && ni < R
            && visited[alp[ni][nj] - 65] == 0) {
            dfs(ni, nj, res + 1);
        }
    }

    visited[alp[i][j] - 65] = 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> R >> C;
    alp.resize(R, std::vector<char>(C));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> alp[i][j];
        }
    }

    dfs(0, 0, 1);   

    std::cout << result;
}