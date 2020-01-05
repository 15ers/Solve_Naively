#include <bits/stdc++.h>

using namespace std;

int m,n;
int adj[100][100];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
bool visited[100][100];
vector<int> s;

int dfs(int cur_y, int cur_x){
	visited[cur_y][cur_x] = true;
	int ret=1;
	for(int i=0;i<4;i++){
		int nxt_y = cur_y+dy[i];
		int nxt_x = cur_x+dx[i];
		if(0<=nxt_x&&nxt_x<n && 0<=nxt_y&&nxt_y<m){
			if(!visited[nxt_y][nxt_x]&&!adj[nxt_y][nxt_x])	ret+=dfs(nxt_y,nxt_x);
		}
	}
	return ret;
}

int dfsAll(){
	int ret = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]&&!adj[i][j]){
				s.push_back(dfs(i,j));
				ret++;
			}
		}
	}
	return ret;
}

int main(){
	int k;
	scanf("%d %d %d",&m,&n,&k);
	memset(adj,0,sizeof(adj));
	fill((bool *)visited,(bool *)visited+100*100,false);
	while(k--){
		int l_x,l_y,r_x,r_y;
		scanf("%d %d %d %d",&l_x,&l_y,&r_x,&r_y);
		l_y = m-l_y-1;
		r_x--;
		r_y = m-r_y;
		for(int i=r_y;i<=l_y;i++)	for(int j=l_x;j<=r_x;j++)	adj[i][j] = 1;
	}
	printf("%d\n",dfsAll());
	sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++)	printf("%d ",s[i]);
	printf("\n");
	
	return 0;
}