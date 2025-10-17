// #344407155 	Oct/17/2025 23:53UTC+2 	trintler 	271A - Beautiful Year 	C++23 (GCC 14-64, msys2) 	Accepted 	124 ms 	100 KB
// worked together on this, with +1mbalance && Valyn.
#include <iostream>
#include <set>
using namespace std;
bool checkDuplicates(int n) {
    set<char> digits;
    string s = to_string(n);
    for (char c : s) {
        if (digits.count(c)) return false;
        digits.insert(c);
    }
    return true;    
}
int main() {
    int n;
    cin >> n;
    
    bool ok = true;
    n++;
    while (!(checkDuplicates(n))) {
        n++;
        
    }
    cout << n << endl;
  return 0;
}
