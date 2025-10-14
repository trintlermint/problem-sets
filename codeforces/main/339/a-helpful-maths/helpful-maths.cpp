// #343694651 	Oct/14/2025 14:26UTC+2 	trintler 	339A - Helpful Maths 	C++23 (GCC 14-64, msys2) 	Accepted 	124 ms 	0 KB

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int c1 = 0, c2 = 0, c3 = 0;
	string res = "";
	for (char c : s)
	{
		if (c == '1') c1++;
		else if (c == '2') c2++;
		else if (c == '3') c3++;
    	}
	for (int i = 0; i < c1; ++i) res += "1+";
	for (int i = 0; i < c2; ++i) res += "2+";
	for (int i = 0; i < c3; ++i) res += "3+";
	cout << res.substr(0,res.length()-1) << endl;
}
