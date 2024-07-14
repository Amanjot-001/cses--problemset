#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n, m;
vector<bool> vis;
vector<vector<int>> adj;

void dfs(int s, vector<int> &component) {
	vis[s] = true;
	component.push_back(s);
	for(int u : adj[s]) {
        if(!vis[u]) {
            dfs(u, component);
        }
    }
}

void solve() {
	cin >> n >> m;
	adj.resize(n+1);
	vis.resize(n+1, false);
	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<int> heads;
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			vector<int> component;
			dfs(i, component);
			heads.push_back(component[0]);
		}
	}

	cout << heads.size() - 1 << '\n';
	for(int i=1; i<heads.size(); i++) {
		cout << heads[i-1] << " " << heads[i] << '\n';
	}

}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	solve();
	return 0;
}