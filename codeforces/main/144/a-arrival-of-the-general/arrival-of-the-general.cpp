// #351660655 	Dec/02/2025 23:26UTC+1 	trintler 	144A - Arrival of the General 	C++23 (GCC 14-64, msys2) 	Accepted 	92 ms 	100 KB
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);

	for(int i = 0; i < n; ++i) cin >> a[i];

	int maxh = -1, minh = 101; int maxidx = -1, minidx = -1;
	for(int i = 0; i < n; ++i)
	{
		if (a[i] > maxh)
		{
			maxh = a[i];
			maxidx = i;
		}
		if (a[i] <= minh)
		{
			minh = a[i];
			minidx = i;
		}
	}

	int ans = maxidx + (n - 1 - minidx);
	if (maxidx > minidx) ans--;
	cout << ans << endl;
	return 0;
}
