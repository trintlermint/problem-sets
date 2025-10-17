// #344103802 	Oct/17/2025 01:46UTC+2 	trintler 	118A - String Task 	C++23 (GCC 14-64, msys2) 	Accepted 	154 ms 	100 KB

#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i<s.length();)
	{
		char c = s[i];
		//c == 'A' || c == 'O' || c == 'Y' || c == 'E' || c == 'U' || c == 'I' ? s.erase(i,1) : (c <= 'Z' && c >= 'A' ? s[i]+=32 : s.insert(i-1,"."));
		if (c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i')
		{
			s.erase(i, 1);
		} else if (c <= 'Z' && c >= 'A') {
			s[i] += 32;
			
		} else {
			s.insert(i, ".");
			i+=2;
		}
	}
	cout << s << endl;
	
}
