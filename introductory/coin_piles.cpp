#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll a, b;
		cin >> a >> b;
	
		// each time 2 and 1 is reduced so (a+b) % 3 == 0
		// now this gap shouldn't be to large else numbers will left in end
		// for this the 2*a>=b && 2*b>=a.... check using 9 4 (no) and 8 4 (yes) test case 
		cout << ((a+b)%3==0 && 2*a>=b && 2*b>=a ? "YES" : "NO") << '\n';
	}
	
	return 0;
}

