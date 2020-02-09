#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
vector<vector<P>> adj;
vector<int> route;
vector<int> point;
priority_queue<P> q;

void dfs(int cur){
	if(cur!=1)	dfs(route[cur]);
	cout << cur << " ";
}

int main(){
	int n,m;
	cin >> n;
	adj.resize(n+1);
	route.resize(n+1);
	point.resize(n+1);
	cin >> m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
	}
	q.push({0,1});
	while(!q.empty()){
		int cur = q.top().second;
		q.pop();
		for(auto &p: adj[cur]){
			int nxt = p.first;
			if(point[nxt]<point[cur]+p.second){
				point[nxt] = point[cur]+p.second;
				route[nxt] = cur;
				if(nxt!=1)	q.push({point[nxt],nxt});
			}
		}
	}
	cout << point[1] << endl;
	dfs(route[1]);
	cout << 1 << endl;
	
	return 0;
}