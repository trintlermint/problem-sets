#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int find_min_coins(const vector<int>& coins, int idx, int sum1, int cnt, int target, vector<vector<int>>& dp) {
    if (sum1 > target) return cnt;
    if (idx == coins.size()) return 1e9;
    if (dp[idx][sum1] != -1) return dp[idx][sum1];
    int pick = find_min_coins(coins, idx + 1, sum1 + coins[idx], cnt + 1, target, dp);
    int skip = find_min_coins(coins, idx + 1, sum1, cnt, target, dp);
    return dp[idx][sum1] = min(pick, skip);
}

int solve(vector<int>& a) {
    sort(a.rbegin(), a.rend());
    int n = a.size();
    int total = 0;
    for (int v : a) total += v;
    int half = total / 2;
    vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
    return find_min_coins(a, 0, 0, 0, half, dp);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cout << solve(a) << endl;
    return 0;
}
