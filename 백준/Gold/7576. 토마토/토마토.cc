#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N;
vector<vector<int>> tomato;
queue<pair<int, int>> q;
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int bfs() {
    int days = 0;
    
    while (!q.empty()) {
        int size = q.size();
        bool ripened = false;
        
        for (int i = 0; i < size; ++i) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int j = 0; j < 4; ++j) {
                int nx = x + directions[j][0];
                int ny = y + directions[j][1];
                
                if (isValid(nx, ny) && tomato[nx][ny] == 0) {
                    tomato[nx][ny] = 1;
                    q.push({nx, ny});
                    ripened = true;
                }
            }
        }
        
        if (ripened) {
            ++days;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (tomato[i][j] == 0) {
                return -1; // 아직 익지 않은 토마토가 남아있는 경우
            }
        }
    }
    
    return days;
}

int main() {
    cin >> M >> N;
    tomato.resize(N, vector<int>(M));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    
    int result = bfs();
    cout << result << endl;
    
    return 0;
}