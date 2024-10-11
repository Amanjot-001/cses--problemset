#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> desired(n);
	vector<ll> apartments(m);

	for(int i=0; i<n; i++)
		cin >> desired[i];

	for(int i=0; i<m; i++)
		cin >> apartments[i];

	sort(desired.begin(), desired.end());
	sort(apartments.begin(), apartments.end());

	int i=0, j=0;
	int ans = 0;
	while(i<n && j<m) {
		if(desired[i] + k >= apartments[j] && desired[i] - k <= apartments[j]) {
			i++;
			j++;
			ans++;
		} else {
			if(desired[i] + k < apartments[j])
				i++;
			else
				j++;
		}
	}

	cout << ans << '\n';
	return 0;
}