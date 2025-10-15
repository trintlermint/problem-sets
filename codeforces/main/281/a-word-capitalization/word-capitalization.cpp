// #343773910 	Oct/14/2025 23:22UTC+2 	trintler 	281A - Word Capitalization 	C++23 (GCC 14-64, msys2) 	Accepted 	92 ms 	0 KB

#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	if ('a' <= s[0] && s[0] <= 'z')
	{
		s[0] = s[0] - ('a' - 'A');
	}
	cout << s << endl;
	return 0;
}
