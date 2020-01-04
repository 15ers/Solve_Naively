#include <bits/stdc++.h>

using namespace std;

int n,cnt;
int adj[100001];
bool visited[100001],finished[100001];

void dfs(int cur){
	visited[cur] = true;
	int nxt = adj[cur];
	if(visited[nxt]){
		if(!finished[nxt]){
			cnt++;
			for(int tmp=nxt;tmp!=cur;tmp=adj[tmp])	cnt++;
		}
	}
	else	dfs(nxt);
	finished[cur] = true;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		cnt=0;
		scanf("%d", &n);
		for(int i=1;i<=n;i++)	scanf("%d", adj+i);
		fill(visited+1,visited+n+1,false);
		fill(finished+1,finished+n+1,false);
		for(int i=1;i<=n;i++)	if(!visited[i])	dfs(i);
		printf("%d\n", n-cnt);
	}
	
	return 0;
}