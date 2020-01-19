#include<bits/stdc++.h>
#define MAX 100000
#define MAX_I 17

using namespace std;

int n,m,par[MAX+1][MAX_I],d[MAX+1];
bool visited[MAX+1];
vector<vector<int> > adj;

void dfs(int cur){
	for(int nxt: adj[cur]){
		if(d[nxt]==-1){
			par[nxt][0] = cur;
			d[nxt] = d[cur]+1;
			dfs(nxt);
		}
	}
}

int main(){
	int u,v;
	scanf("%d",&n);
	adj.resize(n+1);
	memset(par,-1,sizeof(par));
	memset(d,-1,sizeof(d));
	d[1] = 0;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for(int j=1;j<MAX_I;j++){
		for(int i=2;i<=n;i++){
			if(par[i][j-1]!=-1)	par[i][j] = par[par[i][j-1]][j-1];
		}
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d %d",&u,&v);
		if(d[u]<d[v])	swap(u,v);
		int diff = d[u]-d[v];
		for(int i=0;diff;i++){
			if(diff%2)	u = par[u][i];
			diff /= 2;
		}
		if(u!=v){
			for(int i=MAX_I-1;i>=0;i--){
				if(par[u][i]!=-1 && par[u][i]!=par[v][i]){
					u = par[u][i];
					v = par[v][i];
				}
			}
			u = par[u][0];
		}
		printf("%d\n",u);
	}
	
	return 0;
}