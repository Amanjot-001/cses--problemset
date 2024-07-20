// bipartite
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Edge {
public:
	int src;
	int nbr;

	Edge(int src, int nbr) {
		this->src=src;
		this->nbr=nbr;
	}
};

class Graph {
public:
	vector<vector<Edge>> adjList;
	int n;

	Graph(int n) {
		adjList.resize(n);
	}

	void addEdge(int u, int v) {
		adjList[u].emplace_back(u, v);
		adjList[v].emplace_back(v, u);
	}
};

bool bfs(vector<vector<Edge>>& graph, vector<int>& vis, int source) {
	if(graph[source].size() <= 0)
		return true;
	
	queue<pair<int, int>> q;
	int start = graph[source][0].src;
	q.push(make_pair(start, 0));

	vis[start] = 0;

	while(!q.empty()) {
		pair<int, int> rem = q.front();
		q.pop();

		if(vis[rem.first] != -1 && rem.second != vis[rem.first])
			return false;

		vis[rem.first] = rem.second;

		for(Edge e: graph[rem.first]) {
			if(vis[e.nbr] == -1) {
				q.push(make_pair(e.nbr, rem.second + 1));
			}
		}
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;

	Graph graph(n);
	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		graph.addEdge(--u, --v);
	}

	vector<int> vis(n, -1);

	for(int i=0; i<n; i++) {
		if(vis[i] == -1) {
			if(!bfs(graph.adjList, vis, i)) {
				cout << "IMPOSSIBLE" << '\n';
				return 0;
			}
		}
	}

	for(auto lvl: vis) {
		cout << (lvl%2 ? 2 : 1) << " ";
	}
	cout << '\n';

	return 0;
}