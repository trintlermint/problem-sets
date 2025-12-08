#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k, l, m, n, d, res = 0;
	cin >> k >> l >> m >> n >> d;
	for (int i = 1; i <= d; i++)
	{
		res += (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) ? 1 : 0;
	}
	cout << res << '\n';
	return 0;
}
