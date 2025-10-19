// #344653180 	Oct/19/2025 16:00UTC+2 	trintler 	136A - Presents 	C++23 (GCC 14-64, msys2) 	Accepted 	154 ms 	0 KB
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ps(n);
    vector<int> ptrs(n);
    for (int i = 0; i < n; ++i) {
        cin >> ps[i];
    }
    for (int i = 0; i < n; ++i) {
        ptrs[ps[i]-1] = i+1;
    }
    for (int i = 0; i < n; ++i) {
        cout << ptrs[i] << " ";
    }
    cout << endl;
}
