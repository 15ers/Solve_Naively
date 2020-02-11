#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int k,m,p;
		cin >> k >> m >> p;
		vector<vector<int>> adj(m+1),rev(m+1);
		vector<int> indegree(m+1),order(m+1);
		for(int i=0;i<p;i++){
			int a,b;
			cin >> a >> b;
			adj[a].push_back(b);
			rev[b].push_back(a);
			indegree[b]++;
		}
		queue<int> q;
		for(int i=1;i<=m;i++){
			if(!indegree[i]){
				q.push(i);
				order[i] = 1;
			}
		}
		for(int i=0;i<m;i++){
			int cur = q.front();
			q.pop();
			for(int nxt: adj[cur])	if(!(--indegree[nxt]))	q.push(nxt);
			int max_order=0,cnt=0;
			for(int cand: rev[cur])	max_order = max(max_order,order[cand]);
			for(int cand: rev[cur])	if(order[cand]==max_order)	cnt++;
			if(cnt==1)	order[cur] = max_order;
			else	order[cur] = max_order+1;
		}
		cout << k << " " << order[m] << endl;
	}
	
	return 0;
}