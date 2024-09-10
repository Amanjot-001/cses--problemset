#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;

	ll sum = n*(n+1)/2;
	if(sum&1) {
		cout << "NO" << '\n';
	} else {
		ll target = sum/2;
		vector<int> set1, set2;
		ll s1=0;
		for(int i=n; i>0; i--) {
			if(s1 + i <= target) {
				s1 += i;
				set1.push_back(i);
			} else {
				set2.push_back(i);
			}
		}
			
		cout << "YES" << '\n';
		cout << set1.size() << '\n';
		for(const int& it: set1)
			cout << it << " ";
		cout << '\n';
		cout << set2.size() << '\n';
		for(const int& it: set2)
			cout << it << " ";
		cout << '\n';
	}

	return 0;
}

