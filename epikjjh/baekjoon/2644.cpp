#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,s,e,x,y;
	cin >> n;
	vector<vector<int> > adj;
	adj.resize(n);
	vector<bool> visited(n,false);
	cin >> s >> e;
	cin >> m;
	while(m--){
		cin >> x >> y;
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}
	for(int i=0;i<n;i++)	sort(adj[i].begin(),adj[i].end());
	queue<int> q;
	s--;
	e--;
	q.push(s);
	visited[s] = true;
	int ret = 0;
	bool flag=false;
	while(!q.empty()){
		int qs = q.size();
		for(int i=0;i<qs;i++){
			int cur = q.front();
			q.pop();
			if(cur==e){
				flag = true;
				break;
			}
			for(int nxt: adj[cur]){
				if(!visited[nxt]){
					visited[nxt] = true;
					q.push(nxt);
				}
			}
		}
		if(flag)	break;
		ret++;
	}
	if(visited[e])	cout << ret << endl;
	else	cout << -1 << endl;
	
	return 0;
}