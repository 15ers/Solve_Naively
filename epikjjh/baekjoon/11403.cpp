#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int> > adj;
vector<vector<int> > ret;
vector<bool> visited;


void dfs(int cur){
	visited[cur] = true;
	for(int nxt: adj[cur])	if(!visited[nxt])	dfs(nxt);
}

int con(int s, int e){
	for(int t: adj[s]){
		if(!visited[t])	dfs(t);
	}
	if(visited[e])	return 1;
	else	return 0;
}

int main(){
	int t;
	cin >> n;
	adj.resize(n);
	ret.resize(n);
	visited.resize(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> t;
			if(t)	adj[i].push_back(j);
		}
	}
	for(int i=0;i<n;i++)	sort(adj[i].begin(),adj[i].end());
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << con(i,j) << " ";
			fill(visited.begin(),visited.end(),false);
		}
		cout << endl;
	}

	return 0;
}