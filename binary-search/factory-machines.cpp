#include <bits/stdc++.h>
using namespace std;

#define int long long
	
int n, t;
vector<int> arr;

int check(int mid) {
	int total_products = 0;
	for(int i=0; i<n; i++) {
		total_products += mid/arr[i];
		if(total_products >= t) return 1; // prevent overflow
	}
	if(total_products >= t) return 1;
	return 0;
}

int32_t main() {
	cin >> n >> t;
	arr.resize(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];

	int lo=0, hi=t*arr[0], ans=-1;
	while(lo<=hi) {
		int mid = lo + ((hi-lo) >> 1);
		if(check(mid)) {
			hi = mid-1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
	}

	cout << ans << '\n';
}