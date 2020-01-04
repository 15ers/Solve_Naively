#include <bits/stdc++.h>

using namespace std;

int n;
int arr[25][25];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
bool visited[25][25];
vector<int> size;

int dfs(int cur_y, int cur_x){
	visited[cur_y][cur_x] = true;
	int s=1;
	for(int i=0;i<4;i++){
		int nxt_y = cur_y+dy[i];
		int nxt_x = cur_x+dx[i];
		if(0<=nxt_x&&nxt_x<n && 0<=nxt_y&&nxt_y<n){
			if(!visited[nxt_y][nxt_x]&&arr[nxt_y][nxt_x])	s += dfs(nxt_y,nxt_x);
		}
	}
	return s;
}

int dfsAll(){
	int ret=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]&&arr[i][j]){
				size.push_back(dfs(i,j));
				ret++;
			}
		}
	}
	return ret;
}

int main(){
	fill((bool *)visited,(bool *)visited+25*25,false);
	cin >> n;
	for(int i=0;i<n;i++)	for(int j=0;j<n;j++)	scanf("%1d", &arr[i][j]);
	cout << dfsAll() << endl;
	sort(size.begin(),size.end());
	for(int i=0;i<size.size();i++)	cout << size[i] << endl;
	return 0;
}