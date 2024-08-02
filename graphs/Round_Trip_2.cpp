// cycle with topological sort
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

vector<bool> vis;
vector<int> on_stack;
vector<int> cycle;

bool dfs(vector<vector<Edge>>& graph, int src) {
	vis[src]=1;
	on_stack[src]=1;

	for(Edge e : graph[src]) {
		int nbr = e.nbr;
		if(on_stack[nbr]) {
			cycle.push_back(src);
			on_stack[src] = on_stack[nbr] = 0;
			return true;
		} else if(!vis[nbr]) {
			if(dfs(graph, nbr)) {
				if(on_stack[src]) {
					cycle.push_back(src);
					on_stack[src]=0;
					return true;
				} else {
					cycle.push_back(src);
					return false;
				}
			}
		}

		if(!cycle.empty())
			return false;
	}

	on_stack[src] = false;
	return false;
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
	on_stack.resize(n);

	for(int i=0; cycle.empty() && i<n; i++) {
		if(!vis[i])
			dfs(graph.adjList, i);
	}

	if(cycle.empty())
		cout << "IMPOSSIBLE" << '\n';
	else {
		int c = cycle.size();
		cout << c+1 << '\n';
		for(int i=c-1; i>=0; i--)
			cout << cycle[i]+1 << " ";
		cout << cycle[c-1]+1 << '\n';
	}

	return 0;
}
