#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

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
