// dijkstra + dp
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

struct Edge {
	int src, nbr, wt;
	Edge(int src, int nbr, int wt) {
		this->src=src;
		this->nbr=nbr;
		this->wt=wt;
	}
};

struct Graph {
	vector<vector<Edge>> adjList;

	Graph(int n) {
		adjList.resize(n);
	}
	
	void addEdge(int u, int v, int wt) {
		adjList[u].emplace_back(u, v, wt);
	}
};

int n, m;
int MOD = 1e9+7;

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;

	Graph graph(n+1);
	for(int i=0; i<m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;

		graph.addEdge(u, v, wt);
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	vector<bool> vis(n+1, false);
	vector<ll> dist(n+1, LLONG_MAX);
	vector<ll> ways(n+1, 0);
	vector<ll> min_flights(n+1, 0);
	vector<ll> max_flights(n+1, 0);

	dist[1]=0;
	ways[1]=1;
	min_flights[1]=0;
	max_flights[1]=0;

	pq.push({0, 1});
	while(!pq.empty()) {
		auto [wt, src] = pq.top();
		pq.pop();

		if(vis[src])
			continue;
		vis[src]=1;

		for(Edge& e : graph.adjList[src]) {
			ll cost = wt + e.wt;
			if(cost < dist[e.nbr]) {
				dist[e.nbr] = cost;
				ways[e.nbr] = ways[src];
				min_flights[e.nbr] = min_flights[src] + 1;
				max_flights[e.nbr] = max_flights[src] + 1;
				pq.push({cost, e.nbr});
			} else if(cost == dist[e.nbr]) {
				ways[e.nbr] = (ways[src] + ways[e.nbr]) % MOD;
				min_flights[e.nbr] = min(min_flights[e.nbr], min_flights[src] + 1);
				max_flights[e.nbr] = max(max_flights[e.nbr], max_flights[src] + 1);
			}
		}
	}

	cout << dist[n] << " " << ways[n] << " " << min_flights[n] << " " << max_flights[n] << '\n';

	return 0;
}
