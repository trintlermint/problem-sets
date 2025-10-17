// #344357100 	Oct/17/2025 18:38UTC+2 	trintler 	677A - Vanya and Fence 	C++23 (GCC 14-64, msys2) 	Accepted 	77 ms 	100 KB 
#include <iostream>
using namespace std;

int main()
{
	int n, h;
	cin >> n >> h;
	int s = 0;
	for(int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		a>h ? s += 2 : s +=1;
	}
	cout << s << endl;
	
}
