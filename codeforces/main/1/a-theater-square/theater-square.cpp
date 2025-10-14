// #342889579 	Oct/10/2025 13:11UTC+2 	trintler 	1A - Theatre Square 	C++17 (GCC 7-32) 	Accepted 	62 ms 	0 KB

#include <iostream>

using namespace std;
int main()
{
	long long n, m, a;
	cin >> n >> m >> a;
	long long sum = ((n + a - 1)/a) * ((m + a - 1)/a);
	cout << sum << endl;
	return 0;
}
