
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string ch;
        cin >> ch;
        size_t m = ch.size();
        size_t C = 1;
        while (C < m && isdigit(ch[C])) ++C;
        if (C > 1 && C < m && ch[0] == 'R' && ch[C] == 'C') {

            int col = 0;
            for (size_t i = C + 1; i < m; ++i)
                col = col * 10 + (ch[i] - '0');
            int pow = 26;
            while (col > pow) {
                col -= pow;
                pow *= 26;
            }
            col -= 1;
            while (pow != 1) {
                pow /= 26;
                cout << (char)(col / pow + 'A');
                col %= pow;
            }
            cout << ch.substr(1, C-1) << endl;
        }
        else {
            int col = 0, val = 0, pow = 1;
            size_t i = 0;
            while (i < m && isalpha(ch[i])) {
                col += pow;
                pow *= 26;
                val = val * 26 + (ch[i] - 'A');
                ++i;
            }
            col += val;
            cout << "R" << ch.substr(i) << "C" << col << endl;
        }
    }
    return 0;
}
