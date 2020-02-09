#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> adj(n+1);
	vector<int> indegree(n+1),ret(n+1),time(n+1);
	queue<int> q;
	for(int i=1;i<=n;i++){
		int t,u;
		cin >> t;
		time[i] = t;
		while(cin>>u, u!=-1){
			adj[u].push_back(i);
			indegree[i]++;
		}
		if(!indegree[i]){
			ret[i] = time[i];
			q.push(i);
		}
	}
	for(int i=0;i<n;i++){
		int cur = q.front();
		q.pop();
		for(int nxt: adj[cur]){
			ret[nxt] = max(ret[nxt],ret[cur]+time[nxt]);
			if(!(--indegree[nxt]))	q.push(nxt);
		}
	}
	for(int i=1;i<=n;i++)	cout << ret[i] << endl;
	
	return 0;
}