// #345260019 	Oct/22/2025 23:47UTC+2 	trintler 	61A - Ultra-Fast Mathematician 	C++23 (GCC 14-64, msys2) 	Accepted 	62 ms 	0 KB
#include <iostream>
using namespace std;

int main()
{
	string n,m,res;
	cin >> n >> m;
	res = n;
	for (size_t i = 0; i < n.length(); ++i)
	{
		if(n[i] != m[i]) res[i] = '1';
		else res[i] = '0'; 
	} 
	cout << res << endl;
	return 0;
} 
