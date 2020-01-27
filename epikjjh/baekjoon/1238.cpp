#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;
typedef pair<int,int> P;
vector<int> ret;
vector<int> dist;
vector<vector<P>> adj,radj;
vector<bool> visited;
int n,m,x;

void dijkstra(int s,vector<vector<P>> &adj){
	dist[s] = 0;
	priority_queue<P,vector<P>,greater<P>> q;
	q.push(P(0,s));
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
				q.push(P(dist[nxt],nxt));
			}
		}
	}
	for(int i=1;i<=n;i++)	ret[i] += dist[i];
}

int main(){
	scanf("%d %d %d",&n,&m,&x);
	ret.resize(n+1);
	dist.resize(n+1,INF);
	adj.resize(n+1);
	radj.resize(n+1);
	visited.resize(n+1,false);
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back(P(v,w));
		radj[v].push_back(P(u,w));
	}
	dijkstra(x,adj);
	fill(visited.begin(),visited.end(),false);
	fill(dist.begin(),dist.end(),INF);
	dijkstra(x,radj);
	int me=0;
	for(int &e: ret)	me = max(e,me);
	cout << me << endl;
	
	return 0;
}