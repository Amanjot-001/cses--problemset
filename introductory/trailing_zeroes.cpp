#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	
	// no of zeroes is no of times divisible by 10
	// means pairs of {2, 5} in prime factorization of n!
	// since cnt of 5<=2 always in prime fact
	// cnt no of 5's for every multiple of 5 then 25 then 125 and so on
	int ans=0;
	for(int i=5; i<=n; i*=5)
		ans += n/i;

	cout << ans << '\n';

	return 0;
}

