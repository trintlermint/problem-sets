// #342964720 	Oct/10/2025 17:14UTC+2 	trintler 	2153A - Circle of Apple Trees 	C++17 (GCC 7-32) 	Accepted 	77 ms 	0 KB 

#include <iostream>
#include <vector>

#include <set>

using namespace std;

void testing() {
    int n;
    cin >> n;
    
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    
    {
        cin >> b[i];
    }
    
    set<int> distinct;
    
    for (int i = 0; i < n; ++i)
    {
        distinct.insert(b[i]);
    }
    
    cout << distinct.size() << endl;
}

int main() {
        
    int t;
    cin >> t;
    
    while (t--) {
        testing();
    }
    
    return 0;
}
