//#344409330 	Oct/18/2025 00:32UTC+2 	trintler 	266B - Queue at the School 	C++23 (GCC 14-64, msys2) 	Accepted 	124 ms 	100 KB
#include <iostream>

using namespace std;

int main()
{
	int n,t;
	cin >> n >> t;
	string s;
	cin >> s;
	for (int x = 0; x < t; ++x)
	{
		for (int i = 0; i < n-1; ++i)
		{
			if (s[i] == 'B' && s[i+1] == 'G')
			{
				s[i] = 'G';
				s[i+1] = 'B';
				++i;
			}
		
		}
	}
	cout << s << endl;
	
}
