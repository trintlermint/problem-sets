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
