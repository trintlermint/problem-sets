// #350089460 	Nov/21/2025 16:35UTC+1 	trintler 	1472C - Long Jumps 	C++23 (GCC 14-64, msys2) 	Accepted 	390 ms 	0 KB
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);

	for (int &x : a) {
		cin >> x;
	}

	vector<int> dp(n);
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = a[i];
		int j = i + a[i];
		if (j < n) {
			dp[i] += dp[j];
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main()
{
	int tests;
	cin >> tests;
	while (tests-- > 0)
	{
		solve();
	}
	return 0;
}
