#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int coins[n];
    for(int &it: coins) {
        cin >> it;
    }
    
    vector<int> dp(x+1, 1e6+1);
    dp[0] = 0;
	// dp[i] = min coins needed to make sum i
    // dp[i] = min(dp[i], dp[i - coins[j] + 1];

    for(int i=1; i<=x; i++) {
        for(int j=0; j<n; j++) {
			if(coins[j] <= i) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}		
    }
	
	cout << (dp[x] <= 1e6 ? dp[x] : -1) << endl;

    return 0;
}
