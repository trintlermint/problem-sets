#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(--t+1){
		int k, i = 1;
		cin >> k;
		while(true){
			int l = k + i;
			string s = to_string(l);
			string r = s;
			reverse(r.begin(), r.end());
			if (s == r)
			{
				cout << s << endl;
				break;	
			}
			++i;
		}
	}
	return 0;
}
