// #345420945 	Oct/23/2025 23:56UTC+2 	trintler 	A - Even Odds 	C++23 (GCC 14-64, msys2) 	Accepted 	124 ms 	0 KB

#include <iostream>

using namespace std;
#include <vector>
/*
int main()
{
	long long n,k;
	cin >> n >> k;
	vector<long long> ns{};
	vector<long long> nsodd{};
	long long idx = 0,idx2 = 0;
	for(int i = 0; i < n; ++i)
	{
		if(i%2==0)
		{
			ns.push_back(i);
			++idx;
		} else {
			nsodd.push_back(i);
			++idx2;
		}
	}
	if(k <= idx)
	{
		cout << nsodd[k-1] << endl;
	}
	else {
		cout << ns[k-nsodd.size()-1] << endl;
	}
}*/


int main() {
    long long n, k;
    cin >> n >> k;
    long long odds = (n + 1) / 2;

    (k <= odds) ? cout << 2 * k - 1 << endl : cout << 2 * (k - odds) << endl;
}
