// #352617299 	Dec/08/2025 22:08UTC+1 	trintler 	A - Borya's Diagnosis 	C++23 (GCC 14-64, msys2) 	Accepted 	46 ms 	100 KB
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int curr = 0;
    while (n--)
    {
        int s, d; cin >> s >> d;
        curr < s ? curr = s : curr = s + ((curr - s + d) / d) * d;
    }
    cout << curr << '\n';
    return 0;
}
