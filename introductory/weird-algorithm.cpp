// collatz conjecture
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cin.tie(0);
	ll n;
	cin >> n;

	while(n != 1) {
		cout << n << " ";
		if((n&1) == 0) {
			n /= 2;
		} else {
			n = n*3 + 1;
		}
	}

	cout << n;

	return 0;
}