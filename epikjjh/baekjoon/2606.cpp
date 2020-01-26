#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int ret = 0;

void dfs(int cur){
	for(int nxt: adj[cur]){
		if(!visited[nxt]){
			ret++;
			visited[nxt] = true;
			dfs(nxt);
		}
	}
}

int main(){
	int n,t;
	
	cin >> n;
	adj.resize(n+1);
	visited.resize(n+1,false);
	cin >> t;
	while(t--){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	visited[1] = true;
	dfs(1);
	cout << ret << endl;
	
	return 0;
}