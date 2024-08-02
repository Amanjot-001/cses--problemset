#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Edge {
	int src, nbr;

	Edge(int src, int nbr) {
		this->src=src;
		this->nbr=nbr;
	}
};

struct Graph {
	vector<vector<Edge>> adjList;

	Graph(int n) {
		adjList.resize(n);
	}

	void addEdge(int u, int v) {
		adjList[u].emplace_back(u, v);
	}
};

int n, m;

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;

	Graph graph(n);
	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;

		graph.addEdge(--u, --v);
	}

	vector<int> indegeree(n, 0);

	for(auto v : graph.adjList) {
		for(Edge e : v) {
			indegeree[e.nbr]++;
		}
	}

	queue<int> q;
	for(int i=0; i<n; i++) {
		if(indegeree[i] == 0)
			q.push(i);
	}

	vector<int> top_sort;
	while(!q.empty()) {
		int rem = q.front();
		q.pop();

		top_sort.push_back(rem);
		for(Edge e : graph.adjList[rem]) {
			indegeree[e.nbr]--;
			if(indegeree[e.nbr] == 0)
				q.push(e.nbr);
		}
	}

	if(top_sort.size() != n)
		cout << "IMPOSSIBLE" << '\n';
	else {
		for(auto& it: top_sort) {
			cout << it+1 << " ";
		}
		cout << '\n';
	}

	return 0;
}
