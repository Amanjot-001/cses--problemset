#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> dp(n+1, 1e9);
	dp[0] = 0; // number of ops to reach 0

	for(int i=1; i<=n; i++) {
		for(char c: to_string(i)) {
			dp[i] = min(dp[i], dp[i-(c-'0')]+1);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}