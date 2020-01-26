#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
typedef pair<int,int> p;
vector<vector<p>> adj;
int n,e;

int dijkstra(int s, int e){
	vector<int> dist(n+1,INF);
	vector<bool> visited(n+1,false);
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
	return dist[e];
}

int main(){
	scanf("%d %d",&n,&e);
	adj.resize(n+1);
	for(int i=0;i<e;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
	}
	int x,y;
	scanf("%d %d",&x,&y);
	int a1 = dijkstra(1,x);
	int b1 = dijkstra(1,y);
	int mid = dijkstra(x,y);
	int b2 = dijkstra(x,n);
	int a2 = dijkstra(y,n);
	int a,b;
	if(a1==INF || mid==INF || a2==INF)	a = -1;
	else	a = a1+mid+a2;
	if(b1==INF || mid==INF || b2==INF)	b = -1;
	else	b = b1+mid+b2;
	if(a==-1 && b==-1)	printf("-1\n");
	else{
		if(a==-1)	printf("%d\n",b);
		else if(b==-1)	printf("%d\n",a);
		else	printf("%d\n",min(a,b));
	}
	
	return 0;
}