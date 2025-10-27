// #346091871 	Oct/28/2025 00:01UTC+1 	trintler 	32B - Borze 	C++23 (GCC 14-64, msys2) 	Accepted 	124 ms 	0 KB
#include <iostream>
#include <string>
using namespace std;
/*
int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); ++i)
	{
		string t = s.substr(0,i);
		char last_char = s[s.length() - 1];
		string last_two = s.substr(s.length() - 2, 2);
		if (t == "--")
		{
			cout << 2;
			s.erase(0,i);
			i-=i;
		} else if (t == "-.")
		{
			cout << 1;
			s.erase(0,i);
			i-=i;
		} else if (t == "."){
			cout << 0;
			s.erase(0,i);
			i-=i;
		} else if (i = s.length()) {
			if (s[s.length()-1] == '.')
			{
				cout << 0;
			} else if()
		}
	}
	cout << '\n';
	return 0;
}*/

int main() {
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; ) {
        if(s[i] == '.') {
            cout << 0;
            i++;
        } else if(s[i] == '-' && s[i+1] == '-') {
            cout << 2;
            i += 2;
        } else if(s[i] == '-' && s[i+1] == '.') {
            cout << 1;
            i += 2;
        }
    }
    cout << endl;
    return 0;
}
