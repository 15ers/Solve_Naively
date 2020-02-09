#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	vector<int> indegree(n+1);
	for(int i=0;i<m;i++){
		int k,pre,cur;
		cin >> k;
		if(!k)	continue;
		cin >> pre;
		for(int j=1;j<k;j++){
			cin >> cur;
			adj[pre].push_back(cur);
			indegree[cur]++;
			pre = cur;
		}
	}
	queue<int> q;
	vector<int> ret;
	for(int i=1;i<=n;i++)	if(!indegree[i])	q.push(i);
	for(int i=0;i<n;i++){
		if(q.empty()){
			cout << 0 << endl;
			return 0;
		}
		int cur = q.front();
		q.pop();
		ret.push_back(cur);
		for(int nxt: adj[cur])
			if(!(--indegree[nxt]))	q.push(nxt);
	}
	for(int &ans: ret)	cout << ans << endl;
	
	return 0;
}