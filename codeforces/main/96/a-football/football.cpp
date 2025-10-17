#include <iostream>
using namespace std;
/**
int main()
{
	string s;
	cin >> s;
	int c1 = 0, c0 = 0;
	int max_c1, max_c0;
	for (char c : s)
	{
		if (c == '0' && c1 > 0){
			max_c1 = c1;
			c1 = 0;
			++c0;
		} else if (c == '1' && c0 > 0) {
			max_c0 = c0;
			c0 = 0;
			++c1;
		} else if (c == '0') {
			++c0;
		} else {
			++c1;
		}
		if (max_c1 < c1) max_c1 = c1;
		if (max_c0 < c0) max_c0 = c0;
	}
	max_c1 > 6 || max_c0 > 6 ? cout << "YES" << endl : cout << "NO" << endl;
}
// why wont you accept ? =(
**/

int main()
{
	string s;
	cin>>s;
	int c = 1;
	for(int i=1; i<=s.length(); i++){
		if(s[i] == s[i-1]){
			++c;
			if(c==7){
        			cout<<"YES"<<endl;
                		return 0;
            		}
        	} else{
			c=1;
        	}
        }
	cout<<"NO"<<endl;
	return 0;
}
