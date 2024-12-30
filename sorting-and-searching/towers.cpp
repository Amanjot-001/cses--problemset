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

	vector<int> dp;

	for(int i=0; i<n; i++) {
		int l = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();

		if(l == (int)dp.size()) {
			dp.push_back(a[i]);
		} else {
			dp[l] = a[i];
		}
	}

	cout << dp.size() << endl;
	
    return 0;
}
