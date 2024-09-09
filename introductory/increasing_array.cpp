#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	ll moves=0;
	int prev=0;

	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
		if(prev!=0 && a<prev) {
			moves += prev-a;
		} else {
			prev=a;
		}
	}

	cout << moves << '\n';
	return 0;
}