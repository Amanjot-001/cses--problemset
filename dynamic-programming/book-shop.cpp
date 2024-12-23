// 0/1 knapsack
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
	cin >> n >> x;

	vector<int> weight(n), value(n);
	for(int i=0; i<n; i++)
		cin >> weight[i];

	for(int i=0; i<n; i++)
		cin >> value[i];
	
	vector<int> dp(x+1, 0);

	for(int i=0; i<n; i++) {
		for(int j=x; j>=weight[i]; j--) {
			dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
		}
	}

	cout << dp[x] << '\n';

    return 0;
}