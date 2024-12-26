#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;
const int MaxSum = 1e5;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(MaxSum + 1, false)); // sum of j with i coins
	dp[0][0] = true; // sum of 0 with 0 coins

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MaxSum; j++) {
            dp[i][j] = dp[i - 1][j]; // if sum possible with prev coins then also possible with current coins

            int prev = j - coins[i - 1]; // curr sum - curr coin and prev sum should be true then
            if (prev >= 0 && dp[i - 1][prev]) {
                dp[i][j] = true;
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= MaxSum; i++) {
        if (dp[n][i]) {
            ans.push_back(i);
        }
    }

    cout << (int)(ans.size()) << '\n';
    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}
