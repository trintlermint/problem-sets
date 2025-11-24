// #350003762 	Nov/21/2025 01:05UTC+1 	trintler 	939A - Love Triangle 	C++23 (GCC 14-64, msys2) 	Accepted 	46 ms 	0 KB 
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,p;
	cin >> n;
	vector<int> ns(n+1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> p;
		ns[i] = p;
	}
	for(int i = 1; i <= n; ++i)
	{	
		/*
		ns[ns[ns[i]]] == i
		? cout << "YES" << '\n'
		: cout << "NO" << '\n';
		*/
		if (ns[ns[ns[i]]] == i)
		{
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
	return 0;
	
}
