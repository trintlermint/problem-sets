#include <bits/stdc++.h>
using namespace std;

int h, w;
int countN(vector<string>& g, int y, int x) {
    int c = 0;
    for (int dy = -1; dy <= 1; dy++)
        for (int dx = -1; dx <= 1; dx++)
            if ((dy || dx) && y+dy >= 0 && y+dy < h && x+dx >= 0 && x+dx < w && g[y+dy][x+dx] == '@')
                c++;
    return c;
}

int main() {
    vector<string> g;
    string line;
    while (getline(cin, line)) g.push_back(line);
    h = g.size(); w = g[0].size();
    
    int p1 = 0;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (g[y][x] == '@' && countN(g, y, x) < 4) p1++;
    
    auto g2 = g;
    int total = 0;
    while (true) {
        vector<pair<int,int>> rem;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (g2[y][x] == '@' && countN(g2, y, x) < 4)
                    rem.push_back({y, x});
        if (rem.empty()) break;
        total += rem.size();
        for (auto [y, x] : rem) g2[y][x] = '.';
    }
    cout << p1 << "\n" << total << "\n";
}
