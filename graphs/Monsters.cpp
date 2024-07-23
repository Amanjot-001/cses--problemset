// multi source bfs
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<char> directions = {'R', 'D', 'L', 'U'};

void bfs(vector<vector<char>>& grid, queue<pair<int, int>>& q, vector<vector<int>>& visM) {
	int n=grid.size();
	int m=grid[0].size();

	int level=0;
	while(!q.empty()) {
		int size = q.size();
		while(size--) {
			auto [i, j] = q.front();
			q.pop();
		
			if(visM[i][j] != -1)
				continue;
			visM[i][j] = level;

			for(auto& d : dir) {
				int rd = i + d[0];
				int cd = j + d[1];

				if(rd<0 || cd<0 || rd>=n || cd>=m || visM[rd][cd] != -1 || grid[rd][cd] != '.')
					continue;
				
				q.push(make_pair(rd, cd));
			}
		}
		level++;
	}

	return;
}

void bfsMain(vector<vector<char>>& grid, vector<vector<int>>& visM, pair<int, int> start) {
	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> v(n, vector<int>(m, -1));
	vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
	queue<pair<int, int>> q;
	q.push(start);

	int level=0;
	while(!q.empty()) {
		int size = q.size();
		while(size--) {
			auto [i, j] = q.front();
			q.pop();

			if(i == 0 || j == 0 || i == n-1 || j == m-1) {
				vector<pair<int, int>> path;
				path.push_back(make_pair(i, j));
				while(parent[i][j] != make_pair(-1, -1)) {
					auto [pi, pj] = parent[i][j];
                    path.push_back(make_pair(pi, pj));
                    i = pi;
                    j = pj;
				}

				cout << "YES" << '\n';
				cout << path.size()-1 << '\n';
				for(int k=path.size()-1; k>0; k--) {
					auto [pi, pj] = path[k];
					auto [ci, cj] = path[k-1];

					for(int d=0; d<4; d++) {
						if(pi + dir[d][0] == ci && pj + dir[d][1] == cj) {
							cout << directions[d];
							break;
						}
					}
				}
				cout << '\n';
				exit(0);
			}

			if(v[i][j] != -1)
				continue;
			v[i][j] = level;

			for(auto& d : dir) {
				int rd = i + d[0];
				int cd = j + d[1];
				
				if(rd<0 || cd <0 || rd>=n || cd>=m || v[rd][cd] != -1 || grid[rd][cd] != '.' || (level+1 >= visM[rd][cd] && visM[rd][cd] != -1))
					continue;
				
				q.push(make_pair(rd, cd));
				parent[rd][cd] = {i, j};
			}
		}
		level++;
	}

	return;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;

	vector<vector<char>> grid(n, vector<char>(m));
	queue<pair<int, int>> q;
	pair<int, int> start;

	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<m; j++) {
			char ch=s[j];
			if(ch == '#') {
				grid[i][j]='#';
			} else if(ch == 'M') {
				q.push(make_pair(i, j));
				grid[i][j] = 'M';
			} else if(ch == 'A') {
				start = make_pair(i, j);
				grid[i][j] = '.';
			} else {
				grid[i][j] = '.';
			}
		}
	}

	vector<vector<int>> visM(n, vector<int>(m, -1));
	bfs(grid, q, visM);

	bfsMain(grid, visM, start);

	cout << "NO" << '\n';

	return 0;
}
