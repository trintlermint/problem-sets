// #347334795 	Nov/04/2025 02:33UTC+1 	trintler 	122A - Lucky Division 	C++23 (GCC 14-64, msys2) 	Accepted 	92 ms 	0 KB
#include <iostream>
#include <vector>
using namespace std;

void gen(long long current, long long n, vector<long long>& lucky) {
    if (current > n) return;
    if (current != 0) lucky.push_back(current);
    gen(current * 10 + 4, n, lucky);
    gen(current * 10 + 7, n, lucky);
}

int main() {
    long long n;
    cin >> n;

    vector<long long> lucky;
    gen(0, n, lucky);

    bool found = false;
    for (long long l : lucky) {
        if (l != 0 && n % l == 0) {
            found = true;
            break;
        }
    }
    found ? cout << "YES\n" :
    cout << "NO\n";
    return 0;
}
