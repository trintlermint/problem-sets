// #351403720 	Dec/01/2025 02:20UTC+1 	trintler 	405A - Gravity Flip 	C++23 (GCC 14-64, msys2) 	Accepted 	62 ms 	100 KB
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	auto idx = max_element(a.begin(), a.end());
	if(idx == a.end())
	{
		for(int i = 0; i < n; ++i)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
	} else {
		sort(a.begin(), a.end());
		for(int i = 0; i < n; ++i)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
}
