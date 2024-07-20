#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

int bfs(vector<vector<Edge>>& graph, vector<int>& parent) {
	vector<int> vis(graph.size(), false);
	queue<int> q;
	q.push(0);
	vis[0] = true;
	parent[0] = -1;

	int level=0;
	while(!q.empty()) {
		int size = q.size();
		level++;
		while(size--) {
			int rem = q.front();
			q.pop();

			if(rem == graph.size()-1)
				return max(level, 2);

			for(Edge e: graph[rem]) {
				if(vis[e.nbr])
					continue;
				q.push(e.nbr);
				vis[e.nbr] = true;
				parent[e.nbr] = rem;
			}
		}
	}
	return -1;
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

	vector<int> parent(n, -1);

	int ans = bfs(graph.adjList, parent);

	if(ans == -1)
		cout << "IMPOSSIBLE" << '\n';
	else {
		cout << ans << '\n';

		vector<int> path;
        for (int i = n - 1; i != -1; i = parent[i])
            path.push_back(i);

		reverse(path.begin(), path.end());

		for(int node: path) {
			cout << (node + 1) << " ";
		}

		cout << '\n';
	}

	return 0;
}