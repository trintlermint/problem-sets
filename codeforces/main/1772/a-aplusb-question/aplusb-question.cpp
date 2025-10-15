// #343837262 	Oct/15/2025 11:33UTC+2 	trintler 	1772A - A+B? 	C++23 (GCC 14-64, msys2) 	Accepted 	62 ms 	100 KB

#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(--n+1)
	{
		int n, m;
		char c;
		cin >> n >> c >> m;
		
		cout << n+m << endl;
	}
}
