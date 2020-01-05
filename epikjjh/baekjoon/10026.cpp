#include <bits/stdc++.h>

using namespace std;

int n;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int adjH[100][100],adjC[100][100];
bool visitedH[100][100],visitedC[100][100];

void dfs(int cur_x, int cur_y, char sym, int (&adj)[100][100], bool (&visited)[100][100]){
	visited[cur_y][cur_x] = true;
	for(int i=0;i<4;i++){
		int nxt_x = cur_x+dx[i];
		int nxt_y = cur_y+dy[i];
		if(0<=nxt_x&&nxt_x<n && 0<=nxt_y&&nxt_y<n){
			if(!visited[nxt_y][nxt_x]&&sym==adj[nxt_y][nxt_x])	dfs(nxt_x,nxt_y,sym,adj,visited);
		}
	}
}
int dfsAll(int (&adj)[100][100], bool (&visited)[100][100]){
	int ret=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]){
				dfs(j,i,adj[i][j],adj,visited);
				ret++;
			}
		}
	}
	return ret;
}

int main(){
	char c;
	scanf("%d",&n);
	memset(adjH,0,sizeof(adjH));
	memset(adjC,0,sizeof(adjC));
	for(int i=0;i<n;i++){
		getchar();
		for(int j=0;j<n;j++){
			c = getchar();
			adjH[i][j] = c;
			adjC[i][j] = c;
			if(c=='R' || c=='G')	adjC[i][j] = 'R';
		}
	}
	fill((bool *)visitedH,(bool *)visitedH+n,false);
	fill((bool *)visitedC,(bool *)visitedC+n,false);
	printf("%d %d\n",dfsAll(adjH,visitedH),dfsAll(adjC,visitedC));
	
	return 0;
}