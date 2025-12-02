// #351403220 	Dec/01/2025 02:02UTC+1 	trintler 	133A - HQ9+ 	C++23 (GCC 14-64, msys2) 	Accepted 	92 ms 	100 KB
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string p; cin >> p;
	for(char c : p)
	{
		if (c == 'H' || c == 'Q' || c == '9')
		{
			cout << "YES\n"; return 0;
		}
	}
	cout << "NO\n"; return 0;
}
