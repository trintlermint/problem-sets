// #350390173 	Nov/23/2025 17:40UTC+1 	trintler 	1501B - Napoleon Cake 	C++23 (GCC 14-64, msys2) 	Accepted 	93 ms 	0 KB

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> drenched(n);
        int mn = n;
        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, i - a[i]);
            drenched[i] = (mn < i) ? 1 : 0;
        }
        
        for (int i = 0; i < n; i++) {
            cout << drenched[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
