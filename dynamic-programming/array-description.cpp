// paths on grid
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    // base case
    if (arr[0] == 0) {
        for (int j = 1; j <= m; j++)
            dp[0][j] = 1;
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        } else {
            int j = arr[i];
            dp[i][j] = dp[i - 1][j];
            if (j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            if (j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
        }
    }

    int ans = 0;
    if (arr[n - 1] == 0) {
        for (auto it : dp[n - 1])
            ans = (ans + it) % MOD;
    } else {
        ans = dp[n - 1][arr[n - 1]];
    }

    cout << ans << '\n';

    return 0;
}