#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;

	ll ans=0;

	for(int k=1; k<=n; k++) {
		ll n2 = k*k;
		ll pairs = n2*(n2-1)/2; // nC2

		if(k>2) {
			pairs -= 4*(k-1)*(k-2); // ways to form 2*3 rect in board(hori + ver)
		}
		cout << pairs << '\n';
	}

	return 0;
}
