#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;
typedef pair<int,int> P;
vector<vector<P>> adj;

int main(){
	int v,e,k;
	scanf("%d %d %d",&v,&e,&k);
	adj.resize(v+1);
	for(int i=0;i<e;i++){
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		adj[x].push_back({y,w});
	}
	vector<int> dist(v+1);
	vector<bool> visited(v+1);
	fill(dist.begin(),dist.end(),INF);
	priority_queue<P,vector<P>,greater<P>> pq;
	
	dist[k] = 0;
	pq.push({0,k});
	while(!pq.empty()){
		int cur;
		do{
			cur = pq.top().second;
			pq.pop();
		}while(!pq.empty() && visited[cur]);
		if(visited[cur])	break;
		visited[cur] = true;
		for(auto &p: adj[cur]){
			int nxt=p.first,d=p.second;
			if(dist[nxt]>dist[cur]+d){
				dist[nxt] = dist[cur]+d;
				pq.push({dist[nxt],nxt});	
			}
		}
	}
	for(int i=1;i<=v;i++){
		if(dist[i]==INF)	printf("INF\n");
		else	printf("%d\n",dist[i]);
	}
	
	return 0;
}
