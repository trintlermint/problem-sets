// #350084411 	Nov/21/2025 15:59UTC+1 	trintler 	500A - New Year Transportation 	C++23 (GCC 14-64, msys2) 	Accepted 	93 ms 	0 KB 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    
    int current = 1;
    
    while (current < t) {
        current = current + a[current];
    }
    
    current==t ? cout << "YES\n" : cout << "NO\n";
    
    return 0;
}
