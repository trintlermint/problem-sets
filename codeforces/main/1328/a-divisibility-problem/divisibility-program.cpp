// #351403068 	Dec/01/2025 01:55UTC+1 	trintler 	1328A - Divisibility Problem 	C++23 (GCC 14-64, msys2) 	Accepted 	31 ms 	0 KB
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
