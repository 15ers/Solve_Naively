#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;
vector<vector<int>> adj,child;
vector<bool> visited;
int dp[1000000][2],n;

void dfs(int cur){
	visited[cur] = true;
	for(int nxt: adj[cur]){
		if(!visited[nxt]){
			child[cur].push_back(nxt);
			dfs(nxt);
		}
	}
}
int func(int cur, int ispar){
	int &ret=dp[cur][ispar];
	if(ret!=-1)	return ret;
	int notpick=INF,pick=1;
	for(int nxt: child[cur])	pick += func(nxt,1);
	if(ispar){
		notpick = 0;
		for(int nxt: child[cur])	notpick += func(nxt,0);	
	}
	
	return ret=min(pick,notpick);
}

int main(){
	cin >> n;
	adj.resize(n);
	child.resize(n);
	visited.resize(n);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u, &v);
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	cout << func(0,1) << endl;
	
	return 0;
}
