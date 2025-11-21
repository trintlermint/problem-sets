#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    
    vector<string> grid(R);
    
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }
    
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'W') {
                for (int d = 0; d < 4; d++) {
                    int ni = i + dr[d];
                    int nj = j + dc[d];
                    
                    if (ni >= 0 && ni < R && nj >= 0 && nj < C && grid[ni][nj] == 'S') {
                        cout << "No\n";
                        return 0;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '.') {
                grid[i][j] = 'D';
            }
        }
    }
    
    cout << "Yes\n";
    for (int i = 0; i < R; i++) {
        cout << grid[i] << "\n";
    }
    
    return 0;
}
