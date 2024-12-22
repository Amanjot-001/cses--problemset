#include<bits/stdc++.h>
using namespace std;

int main() {
    int mod = 1e9+7;
    int n, x;
    cin >> n >> x;

    int coins[n];
    for(int &it: coins)
        cin >> it;
    
	vector<int> dp(x+1, 0);
	dp[0] = 1;
	// dp[i]= no of ways to make sum i

	for(int i=0; i<n; i++) {
		for(int j=coins[i]; j<=x; j++) {
			dp[j] = (dp[j] + dp[j-coins[i]]) % mod;
		}
	}
	
	cout << dp[x] << endl;
    
    return 0;
}
