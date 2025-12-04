#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    if (!getline(cin, line)) return 0;
    vector<pair<int64,int64>> ranges;
    string cur;
    stringstream ss(line);
    while (getline(ss, cur, ',')) {
        if (cur.empty()) continue;
        auto dash = cur.find('-');
        if (dash == string::npos) continue;
        int64 a = stoll(cur.substr(0, dash));
        int64 b = stoll(cur.substr(dash + 1));
        ranges.emplace_back(a, b);
    }

    if (ranges.empty()) {
        cout << 0 << '\n';
        return 0;
    }
    sort(ranges.begin(), ranges.end());
    vector<pair<int64,int64>> merged;
    merged.push_back(ranges[0]);
    for (size_t i = 1; i < ranges.size(); ++i) {
        auto [l, r] = ranges[i];
        auto &[ml, mr] = merged.back();
        if (l <= mr + 1) {
            mr = max(mr, r);
        } else {
            merged.emplace_back(l, r);
        }
    }
    int64 globalMin = merged.front().first;
    int64 globalMax = merged.back().second;
    auto in_any_range = [&](int64 x) -> bool {
        int lo = 0, hi = (int)merged.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            auto [L, R] = merged[mid];
            if (x < L) hi = mid - 1;
            else if (x > R) lo = mid + 1;
            else return true;
        }
        return false;
    };

    int maxDigits = to_string(globalMax).size();
    int maxHalfDigits = (maxDigits + 1) / 2;

    int64 total = 0;
    for (int len = 1; len <= maxHalfDigits; ++len) {
        int64 start = 1;
        for (int i = 1; i < len; ++i) start *= 10;
        int64 end = start * 10 - 1;
        for (int64 h = start; h <= end; ++h) {
            string s = to_string(h);
            string t = s + s;
            if ((int)t.size() > maxDigits) break;
            int64 val = stoll(t);
            if (val < globalMin) continue;
            if (val > globalMax) break;
            if (in_any_range(val)) {
                total += val;
            }
        }
    }

    cout << total << '\n';
    return 0;
}
