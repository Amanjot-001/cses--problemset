#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int ans = 1;
	int ele = arr[0];

	for(int i=1; i<n; i++) {
		if(ele ^ arr[i]) {
			ele = arr[i];
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}