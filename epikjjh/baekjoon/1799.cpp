#include <bits/stdc++.h>

using namespace std;

int arr[10][10],n,ret[2];

void check(int r, int c, int v){
	for(int i=0;i<n;i++){
		if(r+i>=n || c+i>=n)	continue;
		if(arr[r+i][c+i])	arr[r+i][c+i] += v;
	}
	for(int i=0;i<n;i++){
		if(r-i<0 || c-i<0)	continue;
		if(arr[r-i][c-i])	arr[r-i][c-i] += v;
	}
	for(int i=0;i<n;i++){
		if(r-i<0 || c+i>=n)	continue;
		if(arr[r-i][c+i])	arr[r-i][c+i] += v;
	}
	for(int i=0;i<n;i++){
		if(r+i>=n || c-i<0)	continue;
		if(arr[r+i][c-i])	arr[r+i][c-i] += v;
	}
}

void dfs(int r, int c, int cnt, int type){
	if(c>=n){
		r++;
		if(c%2)	c=0;	
		else	c=1;
	}
	if(r>=n){
		if(type%2)	ret[1] = max(ret[1],cnt);
		else	ret[0] = max(ret[0],cnt);
		return;
	}
	if(arr[r][c]>0){
		check(r,c,-2);
		dfs(r,c+2,cnt+1,type);
		check(r,c,2);
	}
	dfs(r,c+2,cnt,type);
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)	cin >> arr[i][j];
	}
	dfs(0,0,0,0);
	dfs(0,1,0,1);
	cout << ret[0]+ret[1] << endl;
	
	return 0;
}