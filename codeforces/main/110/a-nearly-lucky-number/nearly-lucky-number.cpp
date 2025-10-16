#include <iostream>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	string s = to_string(n);
	int c=0;
	for (char ch:s)
	{
		if (ch == '4' || ch == '7')
		{
			++c;
		}
	}
	bool t = true;
	string cn = to_string(c);
	for (char ch : cn) {
        	if (ch != '4' && ch != '7') {
			t = false;
		}
	}
	t ? cout << "YES" << endl: cout << "NO" << endl;
}
