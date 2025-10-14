// #343326256 	Oct/12/2025 16:54UTC+2 	trintler 	2160A - MEX Partition 	C++17 (GCC 7-32) 	Accepted 	61 ms 	0 KB

#include <iostream>
using namespace std;
#include <vector>
#include <set>

int test(const vector<int>& A) {
        set<int> s(A.begin(), A.end());
        int mex = 0;
        while (s.count(mex)) { ++mex; }
        return mex;
}
int main()
{
	int t, n;
	cin >> t;
	while (--t+1)
	{
		cin >> n;

		vector<int> A(n);
		
		for (int j = 0; j < n; ++j)
		{
			cin >> A[j];	
		}
		cout << test(A) << endl;

		
	}
	return 0;
}
