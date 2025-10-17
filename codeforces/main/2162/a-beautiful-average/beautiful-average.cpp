// #344270891 	00:40:47 	trintler 	A - Beautiful Average 	C++23 (GCC 14-64, msys2) 	Accepted 	77 ms 	0 KB
#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(--t+1)
	{
		int n;
		cin >> n;
		long long a,b = 0;
		for (int i =0 ; i <n; ++i)
		{
			cin >> a;
			if (a > b) b = a;
			
		}
		cout << b << endl;
		
	}
}
