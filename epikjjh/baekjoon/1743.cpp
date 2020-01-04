#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[100][100];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[100][100];

int dfs(int cur_y, int cur_x){
	visited[cur_y][cur_x] = true;
	int ret = 1;
	for(int i=0;i<4;i++){
		int nxt_y = cur_y + dy[i];
		int nxt_x = cur_x + dx[i];
		if(0<=nxt_y&&nxt_y<n && 0<=nxt_x&&nxt_x<m)	if(!visited[nxt_y][nxt_x]&&arr[nxt_y][nxt_x])	ret += dfs(nxt_y,nxt_x);
	}
	return ret;
}
int dfsAll(){
	int ret = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)	if(!visited[i][j]&&arr[i][j])	ret = max(ret,dfs(i,j));
	}
	return ret;
}

int main(){
	int k,a,b;
	memset(arr,0,sizeof(arr));
	fill((bool *)visited,(bool *)visited+100*100,false);
	cin >> n >> m >> k;
	while(k--){
		cin >> a >> b;
		arr[a-1][b-1] = 1;
	}
	cout << dfsAll() << endl;
	
	return 0;
}