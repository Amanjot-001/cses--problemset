#include <bits/stdc++.h>
using namespace std;
using lli = long long;

class Pair {
public:
	int i;
	int j;
	string psf;

	Pair(int i, int j, string psf) {
		this->i=i;
		this->j=j;
		this->psf=psf;
	}
};

int n, m;
vector<vector<bool>> vis;	
vector<vector<char>> arr;
Pair start(0, 0, "");
Pair dest(0, 0, "");

string bfs(vector<vector<char>> &arr, vector<vector<bool>> &vis) {
	vector<tuple<int, int, char>> dir = {{0, 1, 'R'}, {1, 0, 'D'}, {0, -1, 'L'}, {-1, 0, 'U'}};

	queue<Pair> q;
	q.push(start);
	vis[start.i][start.j]=true;

	while(!q.empty()) {
		Pair rem = q.front();
		q.pop();

		if (rem.i == dest.i && rem.j == dest.j)
            return rem.psf;

        for (auto i=0; i<dir.size(); i++) {
            int rdash = rem.i + get<0>(dir[i]);
            int cdash = rem.j + get<1>(dir[i]);
            char move = get<2>(dir[i]);
            
            if (rdash >= 0 && rdash < n && cdash>= 0 && cdash < m && !vis[rdash][cdash] && arr[rdash][cdash] == '.') {
                q.push(Pair(rdash, cdash, rem.psf + move));
                vis[rdash][cdash] = true;
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

	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<m; j++) {
			char ch = s[j];
			if(ch == 'A') {
				start = Pair(i, j, "");
				arr[i][j] = '.';
			}
			else if(ch == 'B') {
				dest = Pair(i, j, "");
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
