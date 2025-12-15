#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<string> grid;
map<pair<int,int>, long long> memo;

long long count_paths(int y, int x) {
    if (y >= h) return 1;
    if (memo.count({y, x})) return memo[{y, x}];
    int ny = y + 1;
    if (ny >= h) return 1;
    long long result;
    if (grid[ny][x] == '^') {
        result = 0;
        if (x - 1 >= 0) result += count_paths(ny, x - 1);
        if (x + 1 < w) result += count_paths(ny, x + 1);
    } else {
        result = count_paths(ny, x);
    }
    return memo[{y, x}] = result;
}

int main() {
    string line;
    while (getline(cin, line)) grid.push_back(line);
    h = grid.size(); w = grid[0].size();
    int sx = 0;
    for (int x = 0; x < w; x++) if (grid[0][x] == 'S') { sx = x; break; }
    
    // Part 1: BFS
    int splits = 0;
    queue<pair<int,int>> Q;
    set<pair<int,int>> V;
    Q.push({0, sx});
    while (!Q.empty()) {
        auto [y, x] = Q.front(); Q.pop();
        if (V.count({y, x})) continue;
        V.insert({y, x});
        int ny = y + 1;
        if (ny >= h) continue;
        if (grid[ny][x] == '^') {
            splits++;
            if (x - 1 >= 0) Q.push({ny, x - 1});
            if (x + 1 < w) Q.push({ny, x + 1});
        } else Q.push({ny, x});
    }
    cout << splits << "\n" << count_paths(0, sx) << "\n";
}
