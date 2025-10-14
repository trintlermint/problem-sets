// #343701755 	Oct/14/2025 15:08UTC+2 	trintler 	879A - Borya's Diagnosis 	C++23 (GCC 14-64, msys2) 	FAILED on test 3 	46 ms 	0 KB 

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int curr = 0;
    
    for (int i = 0; i < n; i++) {
        int s, d;
        cin >> s >> d;
        
        if (curr < s) {
            curr = s;
        } else {
            curr = s + ((curr - s + d - 1)/d)* d;
        }
    }
    
    cout << curr << endl;
    return 0;
}
