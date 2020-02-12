#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n+1);
	vector<vector<int>> cost(n+1,vector<int>(n+1));
	vector<int> indegree(n+1);
	while(m--){
		int x,y,k;
		cin >> x >> y >> k;
		adj[y].push_back({x,k});
		cost[x][y] = k;
		indegree[x]++;
	}
	queue<int> q,ret;
	for(int i=1;i<=n;i++){
		if(!indegree[i]){
			q.push(i);
			ret.push(i);
		}
	}
	for(int i=1;i<=n;i++){
		int cur = q.front();
		q.pop();
		for(auto &p: adj[cur]){
			int nxt = p.first;
			int c = p.second;
			cost[nxt][cur] = c;
			for(int j=1;j<n;j++)	if(cost[cur][j])	cost[nxt][j] += c*cost[cur][j];
			if(!(--(indegree[nxt])))	q.push(nxt);
		}
	}
	while(!ret.empty()){
		int cur = ret.front();
		ret.pop();
		cout << cur << " " << cost[n][cur] << endl;
	}
	
	return 0;
}