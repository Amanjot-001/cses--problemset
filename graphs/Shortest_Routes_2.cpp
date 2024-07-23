// floyd warshall
#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll n, m, q;
	cin >> n >> m >> q;

	vector<vector<ll>> dist(n, vector<ll>(n, LLONG_MAX));

	for(int i=0; i<n; i++)
		dist[i][i] = 0;
	
	for(int i=0; i<m; i++) {
		ll u, v, wt;
		cin >> u >> v >> wt;
		u--, v--;
		dist[u][v] = min(wt, dist[u][v]);
		dist[v][u] = min(wt, dist[v][u]);
	}

	for(int k=0; k<n; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if((dist[i][k] != LLONG_MAX) && (dist[k][j] != LLONG_MAX))
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for(int i=0; i<q; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		cout << (dist[x][y] == LLONG_MAX ? -1 : dist[x][y]) << '\n';
	}
}
