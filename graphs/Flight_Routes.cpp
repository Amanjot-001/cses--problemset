// dijkstra multiple shortest paths
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

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	Graph graph(n);
	for(int i=0; i<m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;

		graph.addEdge(--u, --v, wt);
	}

	priority_queue<ll> bes[n];
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	bes[0].push(0);
	pq.push({0, 0});

	while(!pq.empty()) {
		auto [cost, vtx] = pq.top();
		pq.pop();
		
		if(cost > bes[vtx].top())
			continue;
		
		for(Edge e : graph.adjList[vtx]) {
			ll temp = cost + e.wt;
			if(bes[e.nbr].size() < k) {
				bes[e.nbr].push(temp);
				pq.push({temp, e.nbr});
			} else if(temp < bes[e.nbr].top()) {
				bes[e.nbr].pop();
				bes[e.nbr].push(temp);
				pq.push({temp, e.nbr});
			}
		}
	}

	vector<ll> ans;
	while(!bes[n-1].empty()) {
		ans.push_back(bes[n-1].top());
		bes[n-1].pop();
	}
	reverse(ans.begin(), ans.end());
	for(auto& x : ans)
		cout << x << " ";
	cout << '\n';

	return 0;
}

