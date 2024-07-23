// dijkstra
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Edge {
public:
	int src;
	int nbr;
	int wt;

	Edge(int src, int nbr, int wt) {
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

	void addEdge(int u, int v, int wt) {
		adjList[u].emplace_back(u, v, wt);
	}
};

void dijkstra(vector<vector<Edge>>& graph) {
	int n=graph.size();

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push(make_pair(0, 0));
	vector<ll> vis(n, -1);

	while(!pq.empty()) {
		auto [wt, src] = pq.top();
		pq.pop();

		if(vis[src] != -1)
			continue;
		vis[src] = wt;

		for(Edge e: graph[src]) {
			if(vis[e.nbr] != -1)
				continue;
			pq.push(make_pair(wt + e.wt, e.nbr));
		}
	}

	for(auto& wt: vis)
		cout << wt << " ";
	cout << '\n';
	return;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;

	Graph graph(n);
	for(int i=0; i<m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		graph.addEdge(--u, --v, wt);
	}

	dijkstra(graph.adjList);

	return 0;
}	
