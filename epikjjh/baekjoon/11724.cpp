#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
	int size;
	vector<vector<int> > adj;
	vector<bool> visited;
	
	Graph(int n): size(n){
		adj.resize(size);
		visited.resize(size);
		visited.resize(size);
		fill(visited.begin(),visited.end(),false);
	}
	void addEdge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void sortGraph(){
		for(int i=0;i<size;i++)	sort(adj[i].begin(),adj[i].end());
	}
	int dfsAll(){
		int ret = 0;
		for(int i=0;i<size;i++){
			if(!visited[i]){
				dfs(i);
				ret++;
			}
		}
		return ret;
	}
private:
	void dfs(int cur){
		visited[cur] = true;
		for(int nxt: adj[cur])	if(!visited[nxt])	dfs(nxt);
	}
};

int main(){
	int n,m,u,v;
	scanf("%d %d", &n,&m);
	Graph g(n);
	for(int i=0;i<m;i++){
		scanf("%d %d", &u,&v);
		g.addEdge(u-1,v-1);
	}
	printf("%d\n", g.dfsAll());
	
	return 0;
}