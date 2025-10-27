// #345421535 	Oct/24/2025 00:07UTC+2 	trintler 	520A - Pangram 	C++23 (GCC 14-64, msys2) 	Accepted 	62 ms 	100 KB

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	if(n < 26) { cout << "NO" << endl; return 0;}
	set<char> as;
	for(char ch : s)
	{
		as.insert(tolower(ch));
	}
	(as.size() == 26) ? cout << "YES" << endl: cout << "NO"<<endl;
}
