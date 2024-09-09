#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll y, x;
		cin >> y >> x;
		ll ans=0;

		ll z = max(y, x);
		ll z2 = (z-1)*(z-1); // area of inner sq
		if(z&1) { // odd
			if(y==z) { // y>x
				ans = z2 + x;
			} else { // x>y
				ans = z2 + 2*z - y;
			}
		} else { // even
			if(x==z) { // x>y
				ans = z2 + y;
			} else { // y>x
				ans = z2 + 2*z - x;
			}
		}

		cout << ans << '\n';
	}
}