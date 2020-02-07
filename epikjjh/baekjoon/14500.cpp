#include <bits/stdc++.h>

using namespace std;

int arr[500][500],n,m,ret=0;
int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
bool visited[500][500];

void dfs(int r, int c, int s, int cnt){
	if(cnt==3){
		ret = max(ret,s);
		return;
	}
	for(int i=0;i<4;i++){
		int nr=r+dr[i];
		int nc=c+dc[i];
		if(nr<0 || nr>=n || nc<0 || nc>=m || visited[nr][nc])	continue;
		visited[nr][nc] = true;
		dfs(nr,nc,s+arr[nr][nc],cnt+1);
		visited[nr][nc] = false;
	}
}
void exc(int r, int c){
	if(r+1<n && 0<=c-1 && c+1<m){
		int loc=arr[r][c]+arr[r+1][c]+arr[r][c-1]+arr[r][c+1];
		ret = max(ret,loc);
	}
	if(r-1>=0 && 0<=c-1 && c+1<m){
		int loc=arr[r][c]+arr[r-1][c]+arr[r][c-1]+arr[r][c+1];
		ret = max(ret,loc);
	}
	if(r+1<n && r-1>=0 && c+1<m){
		int loc=arr[r][c]+arr[r-1][c]+arr[r+1][c]+arr[r][c+1];
		ret = max(ret,loc);
	}
	if(r+1<n && r-1>=0 && c-1>=0){
		int loc=arr[r][c]+arr[r-1][c]+arr[r+1][c]+arr[r][c-1];
		ret = max(ret,loc);
	}
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)	cin >> arr[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visited[i][j] = true;
			dfs(i,j,arr[i][j],0);
			visited[i][j] = false;
			exc(i,j);	
		}
	}
	cout << ret << endl;
	
	return 0;
}