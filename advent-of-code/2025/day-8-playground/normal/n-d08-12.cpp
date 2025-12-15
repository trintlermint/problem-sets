#include <bits/stdc++.h>
using namespace std;

struct UF {
    vector<int> p, s;
    UF(int n) : p(n), s(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (s[x] < s[y]) swap(x, y);
        p[y] = x; s[x] += s[y];
        return true;
    }
};

int main() {
    vector<tuple<int,int,int>> pts;
    string line;
    while (getline(cin, line)) {
        int x, y, z;
        sscanf(line.c_str(), "%d,%d,%d", &x, &y, &z);
        pts.push_back({x, y, z});
    }
    int n = pts.size();
    
    vector<tuple<double, int, int>> dists;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto [x1,y1,z1] = pts[i];
            auto [x2,y2,z2] = pts[j];
            double d = sqrt(pow(x1-x2,2) + pow(y1-y2,2) + pow(z1-z2,2));
            dists.push_back({d, i, j});
        }
    }
    sort(dists.begin(), dists.end());
    
    // Part 1
    UF uf1(n);
    int cnt = 0;
    for (auto [d, i, j] :  dists) {
        if (cnt >= 1000) break;
        uf1.unite(i, j);
        cnt++;
    }
    vector<int> sizes;
    for (int i = 0; i < n; i++) if (uf1.find(i) == i) sizes.push_back(uf1.s[i]);
    sort(sizes.rbegin(), sizes.rend());
    cout << (long long)sizes[0] * sizes[1] * sizes[2] << "\n";
    
    // Part 2
    UF uf2(n);
    for (auto [d, i, j] : dists) {
        if (uf2.unite(i, j)) {
            set<int> roots;
            for (int k = 0; k < n; k++) roots.insert(uf2.find(k));
            if (roots.size() == 1) {
                cout << (long long)get<0>(pts[i]) * get<0>(pts[j]) << "\n";
                break;
            }
        }
    }
}
