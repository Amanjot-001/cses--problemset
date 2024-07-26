// bellman ford
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Edge {
public:
	ll src;
	ll nbr;
	ll wt;

	Edge(ll src, ll nbr, ll wt) {
		this->src=src;
		this->nbr=nbr;
		this->wt=wt;
	}
};

class Graph {
public:
	vector<vector<Edge>> adjList;
	int n;

	Graph(int n) {
		adjList.resize(n);
	}

	void addEdge(ll u, ll v, ll wt) {
		adjList[u].emplace_back(u, v, wt);
	}
};

vector<bool> affected;
vector<bool> vis;

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;

	Graph graph(n);

	vector<ll> path(n, LLONG_MIN);
	path[0] = 0;

	affected.resize(n, false);
	vis.resize(n, false);

	// input
	for(int i=0; i<m; i++) {
		ll u, v, wt;
		cin >> u >> v >> wt;
		graph.addEdge(--u, --v, wt);
	}

	// relaxation
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n; j++) {
			for(Edge e : graph.adjList[j]) {
				ll u = e.src;
				ll v = e.nbr;
				ll wt = e.wt;

				if(path[u] == LLONG_MIN)
					continue;
				if(path[u] + wt > path[v]) {
					path[v] = path[u] + wt;
				}
			}
		}
	}

	// cycle check
	for(int j=0; j<n; j++) {
		for(Edge e : graph.adjList[j]) {
			ll u = e.src;
			ll v = e.nbr;
			ll wt = e.wt;

			if(path[u] == LLONG_MIN)
				continue;
			if(path[u] + wt > path[v]) {
				path[v] = path[u] + wt;
				affected[v] = true;
			}
		}
	}

	// reverse edges
	Graph g(n);

	for(int j=0; j<n; j++) {
		for(Edge e : graph.adjList[j]) {
			g.addEdge(e.nbr, e.src, e.wt);
		}
	}

	bool isValid = true;

	// bfs or dfs
	queue<int> q;
	q.push(n-1);

	while(!q.empty()) {
		int rem = q.front();
		q.pop();

		if(vis[rem])
			continue;
		vis[rem] = true;

		if(affected[rem]) {
			isValid=false;
			break;
		}

		for(Edge e : g.adjList[rem]) {
			if(!vis[e.nbr])
				q.push(e.nbr);
		}
	}

	if(path[n-1] >= LLONG_MAX || path[n-1] <= LLONG_MIN || !isValid)
		cout << -1 << '\n';
	else
		cout << path[n-1] << '\n';
	
	return 0;
}
