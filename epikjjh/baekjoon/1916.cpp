#include <bits/stdc++.h>

using namespace std;
const int INF=987654321;
typedef pair<int,int> p;

vector<vector<p>> adj;
vector<bool> visited;
vector<int> dist;

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	adj.resize(n+1);
	visited.resize(n+1);
	dist.resize(n+1);
	fill(visited.begin(),visited.end(),false);
	fill(dist.begin(),dist.end(),INF);
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back(make_pair(v,w));
	}
	int s,e;
	scanf("%d %d",&s,&e);
	priority_queue<p,vector<p>,greater<p>> q;
	dist[s] = 0;
	q.push(make_pair(0,s));
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
	printf("%d\n",dist[e]);
	
	return 0;
}