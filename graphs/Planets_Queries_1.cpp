#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> table;
int MAX=30;

void build(int n) {
	table.resize(MAX+1, vector<int>(n+1));
	for(int i=1; i<=n; i++)
		cin >> table[0][i];
	
	for(int i=1; i<=MAX; i++) {
		for(int j=1; j<=n; j++) {
			if(table[i-1][j] != 0)
				table[i][j] = table[i-1][table[i-1][j]];
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, q;
	cin >> n >> q;

	build(n);

	while(q--) {
		int x, k;
		cin >> x >> k;

		for(int i=0; i<=MAX; i++) {
			int mask = (1<<i);
			if(k&mask) {
				x = table[i][x];
			}
		}

		cout << x << '\n';
	}
	
	return 0;
}