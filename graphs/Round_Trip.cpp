// cycle
#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

vector<int> parent;
vector<bool> vis;

void dfs(vector<vector<Edge>>& graph, int vtx, int p) {
	parent[vtx]=p;
	vis[vtx]=1;

	for(Edge e: graph[vtx]) {
		if(e.nbr == p)
			continue;
		if(vis[e.nbr]) {
			vector<int> path;
			path.emplace_back(e.nbr);
			for(int i=vtx; i!= e.nbr; i=parent[i])
				path.emplace_back(i);
			path.emplace_back(e.nbr);

			cout << path.size()<< '\n';
			for(int i=path.size()-1; i>=0; i--)
				cout << path[i]+1 << " ";
			cout << '\n';
			exit(0);
		} else {
			dfs(graph, e.nbr, vtx);
		}
	}
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

	vis.resize(n, false);
	parent.resize(n, -1);

	for(int i=0; i<n; i++) {
		if(!vis[i])
			dfs(graph.adjList, i, -1);
	}

	cout << "IMPOSSIBLE" << '\n';

	return 0;
}