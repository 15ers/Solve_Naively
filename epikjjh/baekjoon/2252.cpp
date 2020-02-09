#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	vector<int> indegree(n+1),ret;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++)	if(!indegree[i])	q.push(i);
	for(int i=0;i<n;i++){
		int cur = q.front();
		q.pop();
		for(int nxt: adj[cur])	if(!(--indegree[nxt]))	q.push(nxt);
		ret.push_back(cur);
	}
	for(int &p: ret)	cout << p << " ";
	cout << endl;
	
	return 0;
}