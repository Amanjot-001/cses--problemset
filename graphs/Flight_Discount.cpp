// state dijkstra
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

struct Edge {
	int src;
	int nbr;
	int wt;

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

struct Pos {
	int pos;
	bool used;
	ll cost;

	bool operator<(const Pos& rhs) const {
        return cost > rhs.cost;
    }
};

int n, m;

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	Graph graph(n);

	for(int i=0; i<m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;

		graph.addEdge(--u, --v, wt);
	}

	priority_queue<Pos, vector<Pos>, less<Pos>> pq;
	pq.push({0, false, 0});

	vector<vector<ll>> vis(n, vector<ll>(2, LLONG_MAX));
	vis[0] = {0, 0};

	while(!pq.empty()) {
		Pos rem = pq.top();
		pq.pop();

		if(vis[rem.pos][rem.used] != rem.cost)
			continue;
		
		if(rem.pos == n-1)
			break;

		for(Edge e : graph.adjList[rem.pos]) {
			if(!rem.used) {
				ll new_cost = rem.cost + e.wt/2;
				if(new_cost < vis[e.nbr][1]) {
					vis[e.nbr][1] = new_cost;
					pq.push({e.nbr, true, new_cost});
				}
			}
			if(rem.cost + e.wt < vis[e.nbr][rem.used]) {
				vis[e.nbr][rem.used]=rem.cost + e.wt;
				pq.push({e.nbr, rem.used, vis[e.nbr][rem.used]});
			}
		}
	}

	cout << vis[n - 1][1] << '\n';
	return 0;
}
