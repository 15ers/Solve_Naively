#include <bits/stdc++.h>

using namespace std;

int arr[5][5];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
bool visited[5][5];
int n,ret=0;

void dfs(int r, int c, int cnt){
	if(r==4 && c==4){
		if(cnt==n)	ret++;
		return;
	}
	for(int i=0;i<4;i++){
		int nr = r+dr[i];
		int nc = c+dc[i];
		if(nr<0 || nr>4 || nc<0 || nc>4)	continue;
		if(!arr[nr][nc] && !visited[nr][nc]){
			visited[nr][nc] = true;
			dfs(nr,nc,cnt+1);
			visited[nr][nc] = false;
		}
	}
}


int main(){
	int k;
	cin >> k;
	n = 25-k;
	for(int i=0;i<k;i++){
		int r,c;
		cin >> r >> c;
		arr[r-1][c-1] = 1;
	}
	visited[0][0] = true;
	dfs(0,0,1);
	cout << ret << endl;
	
	return 0;
}