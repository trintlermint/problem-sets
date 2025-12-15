#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; 
    cin >> s;

    vector<pair<ll, ll>> R, M;
    for (int i = 0, j; i < s.size(); i = j + 1) {
        j = s.find(',', i); if (j == -1) j = s.size();
        int d = s.find('-', i);
        R.push_back({stoll(s.substr(i, d - i)), stoll(s.substr(d + 1, j - d - 1))});
    }
    sort(R.begin(), R.end());
    for (auto p : R) 
        if (M.empty() || p.first > M.back().second + 1) M.push_back(p); 
        else M.back().second = max(M.back().second, p.second);

    ll mx = M.back().second, res1 = 0, res2 = 0;
    set<ll> S1, S2;

    for (ll len = 1, p10 = 10; len <= 10; ++len, p10 *= 10) {
        ll mul = 1;
        for (int k = 1; k < 60; ++k) {
            if (k > 1) {
                ll start = max(p10 / 10, (M[0].first + mul - 1) / mul);
                ll end = min(p10 - 1, mx / mul);
                if (start > end && (p10 / 10) * mul > mx) break;
                for (ll b = start; b <= end; ++b) {
                    ll v = b * mul;
                    auto it = lower_bound(M.begin(), M.end(), make_pair(v + 1, 0LL));
                    if (it != M.begin() && prev(it)->second >= v) {
                        if (k == 2) S1.insert(v);
                        S2.insert(v);
                    }
                }
            }
            if (__builtin_mul_overflow(mul, p10, &mul)) break;
            mul++;
        }
    }
    for(auto x : S1) res1 += x; 
    for(auto x : S2) res2 += x;
    cout << "p1: " << res1 << " p2: " << res2 << '\n';
    return 0;
}
