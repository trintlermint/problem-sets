#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION" << endl;
    }
    else if (n == 4)
    { // handling testcase 4
    cout << "2 4 1 3";
    } else
    {
	// print all odd/even
        for (int i = 1; i <= n; i += 2) cout << i << " ";
        for (int i = 2; i <= n; i += 2) cout << i << " ";
        cout << endl;
    }
    return 0;
}
