#include <iostream>
#include <vector>
using namespace std;

/*
    1          5
   / \
  2   4
 /
3
*/
int main() {
    int n;
    cin >> n;
    
    vector<int> manager(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> manager[i];
    }
    
    int maxDepth = 1;
    
    for (int i = 1; i <= n; i++) {
        int depth = 1;
        int current = i;
        
        while (manager[current] != -1) {
            depth++;
            current = manager[current];
        }
        
        maxDepth = max(maxDepth, depth);
    }
    
    cout << maxDepth << endl;
    
    return 0;
}
