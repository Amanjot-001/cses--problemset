#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n, m;
vector<vector<bool>> vis;
vector<vector<char>> arr;

void dfs(int i, int j) {
	if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || arr[i][j] == '#')
		return;
	
	vis[i][j] = true;
	
	dfs(i, j-1);
	dfs(i, j+1);
	dfs(i+1, j);
	dfs(i-1, j);

	return;
}

void solve() {
	cin >> n >> m;
	arr.resize(n, vector<char> (m));
	vis.resize(n, vector<bool> (m, false));

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt=0;

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j] == '.' && !vis[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	solve();
	return 0;
}