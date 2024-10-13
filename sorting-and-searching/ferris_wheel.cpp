#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll n, x;
	cin >> n >> x;

	vector<ll> weight(n);
	for(int i=0; i<n; i++)
		cin >> weight[i];

	sort(weight.begin(), weight.end());
	int i=0, j=n-1; 
	int ans=0;

	while(i<=j) {
		if(weight[i] + weight[j] <= x) {
			i++;
			j--;
		} else {
			j--;
		}
		ans++;
	}

	cout << ans << '\n';
	return 0;
}