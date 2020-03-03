#include <bits/stdc++.h>

using namespace std;

int s,e;
bool flag;
vector<int> path,ret;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int cur){
	if(flag)	return;
	if(cur==e){
		ret.resize(path.size());
		copy(path.begin(),path.end(),ret.begin());
		flag = true;
		return;
	}
	for(int nxt: adj[cur]){
		if(!visited[nxt]){
			visited[nxt] = true;
			path.push_back(nxt+1);
			dfs(nxt);
			path.pop_back();
			visited[nxt] = false;
		}
	}
}

int main(){
	int n,k;
	cin >> n >> k;
	adj.resize(n);
	visited.resize(n);
	vector<string> arr(n);
	for(auto &p: arr)	cin >> p;
	for(int i=0;i<n;i++){
		string tar=arr[i];
		for(int j=i+1;j<n;j++){
			string cand=arr[j];
			int s=0;
			for(int l=0;l<k;l++) s += ((tar[l]-'0')^(cand[l]-'0'));
			if(s==1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	cin >> s >> e;
	s--,e--;
	visited[s] = true;
	path.push_back(s+1);
	dfs(s);
	if(flag){
		for(auto p: ret)	cout << p << " ";
		cout << endl;
	}
	else cout << -1 << endl;
	
	return 0;
}