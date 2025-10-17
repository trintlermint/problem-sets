// #344411078 	Oct/18/2025 01:09UTC+2 	trintler 	344A - Magnets 	C++23 (GCC 14-64, msys2) 	Accepted 	186 ms 	0 KB
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string r;
	cin >> r;
	int g = 1;
	while(--n)
	{
		string s;
		cin >> s;
		if (s[1] == r[0]){
			r = s;
			++g;
		}
		else
		{
			r = s;
		}	
	}
	cout << g << endl;
}
