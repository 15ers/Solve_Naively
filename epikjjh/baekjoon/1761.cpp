#include <bits/stdc++.h>
#define MAX 40000
#define MAX_I 16

using namespace std;

typedef vector<vector<pair<int,int> > > VP;

int n,m,par[MAX+1][MAX_I],depth[MAX+1],dist[MAX+1];
VP adj;

void dfs(int cur){
	for(auto &p: adj[cur]){
		int nxt = p.first;
		if(depth[nxt]==-1){
			depth[nxt] = depth[cur]+1;
			par[nxt][0] = cur;
			dist[nxt] = dist[cur]+p.second;
			dfs(nxt);
		}
	}
}

int main(){
	int u,v,w;
	adj.resize(MAX+1);
	memset(depth,-1,sizeof(depth));
	memset(par,-1,sizeof(par));
	depth[1] = 0;
	dist[1] = 0;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	dfs(1);
	for(int j=1;j<MAX_I;j++){
		for(int i=1;i<=n;i++){
			if(par[i][j-1]!=-1)	par[i][j] = par[par[i][j-1]][j-1];
		}
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d %d",&u,&v);
		int u_o=u,v_o=v;
		if(depth[u]<depth[v])	swap(u,v);
		int diff = depth[u]-depth[v];
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
		printf("%d\n",dist[u_o]+dist[v_o]-2*dist[u]);
	}
	return 0;
}