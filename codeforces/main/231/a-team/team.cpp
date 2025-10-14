// #343615991 	Oct/14/2025 00:21UTC+2 	trintler 	231A - Team 	C++23 (GCC 14-64, msys2) 	Accepted 	92 ms 	0 KB

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int a,b,c;
		cin >> a >> b >> c;

		if (a+b+c > 1)
		{
			sum += 1;
		}
		else
		{
			continue;
		}
	}
	cout << sum << endl;
	return 0;
}
