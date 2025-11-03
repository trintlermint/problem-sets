#include <bits/stdc++.h>
using namespace std;

int dp[21][11][156];

int gen(int n, int k, int s, int p = 1)
{
    if(k == 0 && s == 0) return 1;

    if(k == 0 || s == 0 || p > n) return 0;

    int &ret = dp[p][k][s];
    if(ret != -1) return ret;

    ret = gen(n,k,s,p+1);
    if(s >= p)
    {
        ret += gen(n,k-1,s-p, p+1);
    }
    return ret;
}
int main()
{
    int n,k,s;
    while(true)
    {
        cin >> n >> k >> s;
        // n = max elem
        // k = num of elems
        // s = sum of all
        if(n == 0 && k == 0 && s == 0) break;
        memset(dp,-1,sizeof(dp));
        cout << gen(n,k,s) << '\n';
    }
}
