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
