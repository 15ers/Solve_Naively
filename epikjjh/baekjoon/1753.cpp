#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;
typedef pair<int,int> p;
vector<vector<p>> adj;

int main(){
	int v,e,k;
	scanf("%d %d %d",&v,&e,&k);
	adj.resize(v+1);
	for(int i=0;i<e;i++){
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		adj[x].push_back(make_pair(y,w));
	}
	vector<int> dist(v+1);
	vector<bool> visited(v+1);
	fill(dist.begin(),dist.end(),INF);
	fill(visited.begin(),visited.end(),false);
	priority_queue<p,vector<p>,greater<p>> q;
	
	dist[k] = 0;
	q.push(make_pair(0,k));
	while(!q.empty()){
		int cur;
		do{
			cur = q.top().second;
			q.pop();
		}while(!q.empty() && visited[cur]);
		if(visited[cur])	break;
		visited[cur] = true;
		for(auto &p: adj[cur]){
			int nxt=p.first,d=p.second;
			if(dist[nxt]>dist[cur]+d){
				dist[nxt] = dist[cur]+d;
				q.push(make_pair(dist[nxt],nxt));	
			}
		}
	}
	for(int i=1;i<=v;i++){
		if(dist[i]==INF)	printf("INF\n");
		else	printf("%d\n",dist[i]);
	}
	
	return 0;
}