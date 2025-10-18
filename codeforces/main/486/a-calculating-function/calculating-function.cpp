// #344462948 	Oct/18/2025 10:34UTC+2 	trintler 	486A - Calculating Function 	C++23 (GCC 14-64, msys2) 	Accepted 	62 ms 	100 KB
#include <iostream>
using namespace std;   
int main()
{
	long long n;
	cin >> n;
	long long sum = (n % 2 == 0) ? (n/2) : -(n+1)/2;
	cout << sum << endl;
}
