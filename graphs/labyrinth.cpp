#include <bits/stdc++.h>
using namespace std;
using lli = long long;

class Pair {
public:
	int i;
	int j;

	Pair(int i, int j) {
		this->i=i;
		this->j=j;
	}
};

int n, m;
vector<vector<bool>> vis;
vector<vector<char>> arr;
Pair start(0, 0);
Pair dest(0, 0);

vector<vector<pair<int, int>>> parent;

string bfs(vector<vector<char>> &arr, vector<vector<bool>> &vis) {
	vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

	queue<Pair> q;
	q.push(start);
	vis[start.i][start.j]=true;
	parent[start.i][start.j] = {-1, -1};

	while(!q.empty()) {
		Pair rem = q.front();
		q.pop();

		if (rem.i == dest.i && rem.j == dest.j) {
			string path;
			Pair p = dest;

			while (parent[p.i][p.j].first != -1 && parent[p.i][p.j].second != -1) {
                int pi = parent[p.i][p.j].first;
                int pj = parent[p.i][p.j].second;
                if (pi == p.i) {
                    path += (pj < p.j) ? 'R' : 'L';
                } else {
                    path += (pi < p.i) ? 'D' : 'U';
                }
                p = Pair(pi, pj);
            }
            reverse(path.begin(), path.end());
            return path;
		}

        for (auto i=0; i<dir.size(); i++) {
            int rdash = rem.i + dir[i].first;
            int cdash = rem.j + dir[i].second;
            
            if (rdash >= 0 && rdash < n && cdash>= 0 && cdash < m && !vis[rdash][cdash] && arr[rdash][cdash] == '.') {
                q.push(Pair(rdash, cdash));
                vis[rdash][cdash] = true;
				parent[rdash][cdash] = {rem.i, rem.j};
            }
        }
	}
	return "";
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	arr.resize(n, vector<char> (m));
	vis.resize(n, vector<bool> (m, false));
	parent.resize(n, vector<pair<int, int>>(m, {-1, -1}));

	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<m; j++) {
			char ch = s[j];
			if(ch == 'A') {
				start = Pair(i, j);
				arr[i][j] = '.';
			}
			else if(ch == 'B') {
				dest = Pair(i, j);
				arr[i][j] = '.';
			}
			else {
				arr[i][j]=ch;
			}
		}
	}

	string spath = bfs(arr, vis);

	if(spath.size() > 0) {
		cout << "YES" << '\n';
		cout << spath.size() << '\n';
		cout << spath << '\n';
	} else {
		cout << "NO" << '\n';
	}
	
	return 0;
}
