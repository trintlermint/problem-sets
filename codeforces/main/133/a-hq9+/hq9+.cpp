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
