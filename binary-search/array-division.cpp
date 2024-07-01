#include <bits/stdc++.h>
using namespace std;

#define int long long
	
int n, k;
vector<int> arr;

int check(int mid) {
	int sum_left=0;
	int divisions_made=0;

	for(int i=0; i<n; i++) {
		if(sum_left >= arr[i])
			sum_left -= arr[i];
		else {
			divisions_made++;
			if(divisions_made > k)
				return 0;
			sum_left = mid;
			if(sum_left >= arr[i])
				sum_left -= arr[i];
			else
				return 0;
		}
	}
	return 1;
}

int32_t main() {
	cin >> n >> k;
	arr.resize(n);
	int sum=0;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	int lo=0, hi=sum, ans=sum;
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