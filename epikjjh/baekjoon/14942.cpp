#include <bits/stdc++.h>
#define MAX 100000
#define MAX_I 17

using namespace std;

typedef vector<vector<pair<int,int> > > VP;

int n,par[MAX+1][MAX_I],dist[MAX+1],energy[MAX+1];
VP adj;

void dfs(int cur){
	for(auto p: adj[cur]){
		int nxt=p.first;
		if(dist[nxt]==-1){
			dist[nxt] = dist[cur]+p.second;
			par[nxt][0] = cur;
			dfs(nxt);
		}
	}
}

int main(){
	int u,v,w;
	memset(par,-1,sizeof(par));
	memset(dist,-1,sizeof(dist));
	adj.resize(MAX+1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%d",&energy[i]);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	dist[1] = 0;
	dfs(1);
	for(int j=1;j<MAX_I;j++){
		for(int i=1;i<=MAX;i++){
			if(par[i][j-1]!=-1)	par[i][j] = par[par[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		int cur=i,e=energy[i];
		for(int j=MAX_I-1;j>=0;j--){
			int nxt=par[cur][j];
			int nxt_e=dist[cur]-dist[nxt];
			if(nxt==-1 || e<nxt_e)	continue;
			cur = nxt;
			e -= nxt_e;
		}
		printf("%d\n",cur);
	}
	return 0;
}