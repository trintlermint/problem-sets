// #344325892 	Oct/17/2025 18:05UTC+2 	trintler 	2162B - Beautiful String 	C++23 (GCC 14-64, msys2) 	Accepted 	93 ms 	0 KB 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        bool truth = false;
        for(int i = 0; i < (1<<n); ++i)
        {
            string p;
            vector<int> id;
            string x;
            for(int j = 0; j < n; ++j)
            {
                if ((i >> j) & 1) p += s[j], id.push_back(j+1);
                else x += s[j];
            }
            bool nond = true;
            for(int j = 1; j < (int)p.size(); ++j)
            {
                if (p[j] < p[j-1]) { nond = false; break; }
            }
            bool palin = true;
            int l = 0, r = x.size() - 1;
            while (l < r)
            {
                if (x[l] != x[r]) { palin = false; break; }
                ++l; --r;
            }
            if (nond && palin)
            {
                cout << id.size() << endl;
                for (int k = 0; k < id.size(); ++k)
                {
                    cout << id[k] << (k+2 == id.size() ? "\n" : " ");
                }
                truth = true;
                break;
            }
        }
        if (!truth) cout << "-1" << endl;
    }
}
