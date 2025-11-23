// #350265364 	Nov/23/2025 02:54UTC+1 	trintler 	705A - Hulk 	C++23 (GCC 14-64, msys2) 	Accepted 	46 ms 	0 KB
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s = "";
	for(int i = 1; i <= n; ++i)
	{
		i < n
		? i % 2 == 1
		        ? s += "I hate that"
		        : s += " I love that "
		: i % 2 == 1
		        ? s += "I hate it" 
			: s += " I love it "
		;
	}
	cout << s << '\n';
	return 0;
}
