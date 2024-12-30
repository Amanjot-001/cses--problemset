#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	vector<int> dp(n+1, INF);
	dp[0] = -INF;

	for(int i=0; i<n; i++) {
		int l = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin(); // element just bigger than a[i]

		if(dp[l-1] < a[i] && a[i] < dp[l])
			dp[l] = a[i];
	}

	int ans = 0;
	for(int l=0; l<=n; l++) {
		if(dp[l] < INF)
			ans = l;
	}

	cout << ans << endl;
	
    return 0;
}
