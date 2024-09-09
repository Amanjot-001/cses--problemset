#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	ll sum=0;

	for(int i=1; i<n; i++) {
		int a;
		cin >> a;
		sum += a;
	}

	cout << n*(n+1)/2 - sum << '\n'; 
	return 0;
}