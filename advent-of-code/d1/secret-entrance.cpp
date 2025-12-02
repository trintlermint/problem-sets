#include <bits/stdc++.h>
using namespace std;
int main()
{
	int p1 = 50, p2 = 50, res1 = 0, res2 = 0;
	string in;
	while(cin >> in)
	{
		// part 1:
		char c = in[0]; int rot = stoi(in.substr(1));
		if((p1=(p1+(c=='R'?rot:-rot)+100)%100)==0) ++res1;
		// part 2:
		int posn = (c == 'R') ? p2 + rot : p2 - rot; if(posn <= 0 && p2 != 0) ++res2;
		p2 = ((posn % 100) + 100) % 100; res2 += abs(posn) / 100;
	}
	cout << "p1: " << res1 << " p2: " << res2 << '\n';
	return 0;
}
