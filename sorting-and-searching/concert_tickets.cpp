#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);

	multiset<int, greater<int>> s;

	for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

	 for (int i = 0; i < m; i++) {
        auto it = s.lower_bound(b[i]);
        if (it == s.end()) {
            cout << -1 << '\n';
        } else {
            cout << *it << '\n';
            s.erase(it);
        }
    }
	
	return 0;
}