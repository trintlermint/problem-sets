// #343777528 	Oct/15/2025 00:28UTC+2 	trintler 	266A - Stones on the Table 	C++23 (GCC 14-64, msys2) 	Accepted 	154 ms 	100 KB

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, c = 0;
	cin >> n;
	string s;
	cin >> s;

	for (int i = 0; i < s.size()-1; ++i)
	{
		if (s[i] == s[i+1])
		{
			s.erase(i, 1);
			++c;
			--i;
		}
	}
	cout << c << endl;
	return 0;
}
