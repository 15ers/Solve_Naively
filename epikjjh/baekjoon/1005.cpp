#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> indegree,times,ret;

int main(){
	int t;
	cin >> t;
	while(t--){
		adj.clear();
		times.clear();
		indegree.clear();
		ret.clear();
		int n,k;
		cin >> n >> k;
		adj.resize(n+1);
		times.resize(n+1);
		indegree.resize(n+1);
		ret.resize(n+1);
		for(int i=1;i<=n;i++)	cin >> times[i];
		for(int i=0;i<k;i++){
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			indegree[v]++;
		}
		queue<int> q;
		for(int i=1;i<=n;i++){
			if(!indegree[i]){
				q.push(i);
				ret[i] = times[i];
			}
		}
		for(int i=0;i<n;i++){
			int cur = q.front();
			q.pop();
			for(int nxt: adj[cur]){
				ret[nxt] = max(ret[nxt],times[nxt]+ret[cur]);
				if(!(--indegree[nxt]))	q.push(nxt);
			}
		}
		int w;
		cin >> w;
		cout << ret[w] << endl;
	}
	
	return 0;
}