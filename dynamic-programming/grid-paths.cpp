#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid[i] = s;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j] == '*' ? 0 : 1;
            } else if (i == 0) {
                dp[i][j] = grid[i][j] == '*' ? 0 : dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = grid[i][j] == '*' ? 0 : dp[i - 1][j];
            } else {
                dp[i][j] = grid[i][j] == '*' ? 0 : (dp[i][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] << '\n';

    return 0;
}