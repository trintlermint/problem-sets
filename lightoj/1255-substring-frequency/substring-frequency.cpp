#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        string a, b;
        cin >> a >> b;
        int count = 0;
        for (size_t i = 0; i + b.size() - 1 < a.size(); i++) {
            if (a.substr(i, b.size()) == b) {
                count++;
            }
        }
        cout << "Case " << i << ": " << count << endl;
    }
    return 0;
}
