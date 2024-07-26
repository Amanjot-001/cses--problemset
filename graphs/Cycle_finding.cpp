// negative cycle printing
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
	
	vector<ll> path(n, 0);
	vector<int> parent(n, -1);
	path[0] = 0;

	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n; j++) {
			for(Edge e : graph.adjList[j]) {
				auto [u, v, wt] = e;

				if(path[u] != LLONG_MIN && path[u] + wt < path[v]){
					path[v] = max(path[u] + wt, LLONG_MIN);
					// x = v;
					parent[v] = u;
			}
			}
		}
	}

	int x = -1;
	for(int j=0; j<n; j++) {
    	for(Edge e : graph.adjList[j]) {
   			auto [u, v, wt] = e;

       		if(path[u] != LLONG_MIN && path[u] + wt < path[v]) {
            	path[v] = max(path[u] + wt, LLONG_MIN);
				x = v;
				parent[v] = u;
			}
        }
	}

	if(x == -1) {
		cout << "NO" << '\n';
	} else {
		for(int i=0; i<n; i++)
			x = parent[x];
		
		vector<int> cycle;
		for(int v = x; ; v=parent[v]) {
			cycle.push_back(v);
			if(v==x && cycle.size() > 1)
				break;
		}

		cout << "YES" << '\n';
		for(int i=cycle.size()-1; i>=0; i--)
			cout << cycle[i] + 1 << " ";
		cout << '\n';
	}

	return 0;
}
