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
