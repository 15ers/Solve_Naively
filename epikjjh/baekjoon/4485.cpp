#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;
typedef pair<int,int> P;
int n;

int dijkstra(){
	vector<vector<P>> adj(n*n+1);
	vector<bool> visited(n*n+1,false);
	vector<int> dist(n*n+1,INF);
	int fin;
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			int cur=i*n+j;
			int w;
			scanf("%d",&w);
			for(int k=0;k<4;k++){
				int nxt;
				if(k<2){
					if(cur%n==1){
						if(k%2)	continue;
						nxt = cur+1;
					}
					else if(cur%n==0){
						if(k%2)	continue;
						nxt = cur-1;
					}
					else	nxt = cur + 1*(k%2 ? 1 : -1);
				}
				else	nxt = cur + n*(k%2 ? 1 : -1);
				if(nxt<1 || nxt>n*n)	continue;
				adj[cur].push_back(make_pair(nxt,w));
			}
			if(i==n-1 && j==n)	fin = w;
		}
	}
	dist[1] = 0;
	priority_queue<P,vector<P>,greater<P>> q;
	q.push(make_pair(0,1));
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
	return dist[n*n]+fin;
}

int main(){
	int t=1;
	while(scanf("%d",&n), n){
		printf("Problem %d: %d\n",t,dijkstra());
		t++;
	}
	
	return 0;
}