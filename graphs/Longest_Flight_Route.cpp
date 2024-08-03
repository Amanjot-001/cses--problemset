// longest path in DAG
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

	vector<int> indegree(n, 0);
	vector<int> top_sort;
	queue<int> q;

	for(auto& v : graph.adjList) {
		for(Edge& e : v) {
			indegree[e.nbr]++;
		}
	}

	for(int i=0; i<n; i++) {
		if(indegree[i] == 0)
			q.push(i);
	}

	while(!q.empty()) {
		int rem = q.front();
		q.pop();

		top_sort.push_back(rem);
		for(Edge e : graph.adjList[rem]) {
			indegree[e.nbr]--;
			if(indegree[e.nbr] == 0)
				q.push(e.nbr);
		}
	}
	
	vector<int> dist(n, INT_MIN); // dp
	vector<int> par(n, -1);
	dist[0]=0;

	for(int i=0; i<top_sort.size(); i++) {
		int rem = top_sort[i];
		if(dist[rem] == INT_MIN)
			continue;
		
		for(Edge e : graph.adjList[rem]) {
			if(dist[rem] + 1 > dist[e.nbr]) {
				dist[e.nbr] = dist[rem] + 1;
				par[e.nbr] = rem;
			}
		}
	}
	
	vector<int> path;
	bool contains_1 = false;
	for(int i=n-1; i != -1; i = par[i]) {
		path.push_back(i);
		if(i == 0) {
			contains_1 = true;
			break;
		}
	}

	if(!contains_1) {
		cout << "IMPOSSIBLE" << '\n';
		exit(0);
	}

	cout << dist[n-1]+1 << '\n';
	for(int i=path.size()-1; i>=0; i--) {
		cout << path[i]+1 << " ";
	}
	cout << '\n';

	return 0;
}
