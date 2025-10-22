// #344829872 	Oct/20/2025 10:25UTC+2 	trintler 	228A - Is your horseshoe on the other hoof? 	C++23 (GCC 14-64, msys2) 	Accepted 	124 ms 	0 KB
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<long long> hs;
	for(int i = 0; i < 4; ++i)
	{
		long long x;
		cin >> x;
		hs.insert(x);
	}
	cout << 4 - hs.size() << endl;
}
