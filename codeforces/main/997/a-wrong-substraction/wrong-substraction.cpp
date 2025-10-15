// #343845102 	Oct/15/2025 12:35UTC+2 	trintler 	977A - Wrong Subtraction 	C++23 (GCC 14-64, msys2) 	Accepted 	62 ms 	100 KB

#include <iostream>

using namespace std;

int main()
{
	string n;
	int k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		if (n[n.length()-1] == '0') n.erase(n.length()-1, 1);
		else n[n.length()-1] = (n[n.length()-1] - '0' - 1) + '0';
	}
	cout << n << endl;
}
