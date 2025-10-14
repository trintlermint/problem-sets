#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}

vector<int> prange(int n, int m) {
    vector<int> ps;
    for (int i = max(2, n); i <= m; ++i)
        if (is_prime(i)) ps.push_back(i);
    return ps;
}

int main()
{
	int t;
	cin >> t;
	
	while(--t+1)
	{
		int n,m;
		cin >> n >> m;
		vector<int> ps = prange(n, m);
		for (int p : ps) cout << p << endl;
	}
}
