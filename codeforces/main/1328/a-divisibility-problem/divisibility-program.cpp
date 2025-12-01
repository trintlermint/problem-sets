#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        if (b == 0) {
            cout << 0 << '\n';
            continue;
        }
        long long r = a % b;
        cout << ( (r == 0) ? 0 : (b - r) ) << '\n';
    }
    return 0;
}
