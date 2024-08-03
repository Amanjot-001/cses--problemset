// kahn's + dp
// rev graph for prev nodes
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
int MOD = 1e9+7;

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;

	Graph graph(n+1), rgraph(n+1);
	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;

		graph.addEdge(u, v);
		rgraph.addEdge(v, u);
	}

	vector<int> indegree(n+1, 0);
	vector<int> dp(n+1, 0);
	dp[1]=1;
	queue<int> q;

	for(auto& v : graph.adjList) {
		for(Edge& e : v) {
			indegree[e.nbr]++;
		}
	}

	for(int i=1; i<=n; i++) {
		if(indegree[i] == 0)
			q.push(i);
	}

	while(!q.empty()) {
		int rem = q.front();
		q.pop();

		for(Edge e : graph.adjList[rem]) {
			indegree[e.nbr]--;
			if(indegree[e.nbr] == 0)
				q.push(e.nbr);
		}

		for(Edge e : rgraph.adjList[rem]) {
			dp[rem] = (dp[rem] + dp[e.nbr]) % MOD;
		}
	}

	cout << dp[n] << '\n';

	return 0;
}
