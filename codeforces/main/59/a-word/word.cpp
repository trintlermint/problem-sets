// #343841685 	Oct/15/2025 12:08UTC+2 	trintler 	59A - Word 	C++23 (GCC 14-64, msys2) 	Accepted 	124 ms 	100 KB

#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int cu = 0, cl = 0;
    for (char c : s)
    {
        if (c >= 'A' && c <= 'Z') ++cu;
        else if (c >= 'a' && c <= 'z') ++cl;
    }
    if (cu > cl)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
        }
    }
    else
    {
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
        }
    }
    cout << s << endl;
    return 0;
}
