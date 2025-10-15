
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(--t+1)
    {
        int n;
        cin >> n;
        int pos = n;
        for (int i = 1; i < n; ++i)
        {
            int k = n -i;
            if (i % 2 == 1)
            {
                pos -= k;
            } else {
                pos += k;
    
            }
        }
        cout << pos << endl;
    }
}
