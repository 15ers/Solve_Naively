#include <bits/stdc++.h>

using namespace std;

int arr[9][9];
int row[9][9];
int col[9][9];
int seg[9][9];

bool route(int r, int c, int i){
	if(row[r][i-1])	return false;
	if(col[c][i-1])	return false;
	int s=int(r/3)*3+int(c/3);
	if(seg[s][i-1])	return false;
	return true;
}

bool solve(int cur){
	if(cur>80)	return true;
	int r=cur/9,c=cur%9;
	int s=int(r/3)*3+int(c/3);
	if(arr[r][c]){
		if(solve(cur+1))	return true;
		else	return false;
	}
	for(int i=1;i<=9;i++){
		if(route(r,c,i)){
			arr[r][c] = i;
			row[r][i-1] = 1;
			col[c][i-1] = 1;
			seg[s][i-1] = 1;
			if(solve(cur+1))	return true;
			arr[r][c] = 0;
			row[r][i-1] = 0;
			col[c][i-1] = 0;
			seg[s][i-1] = 0;
		}
	}
	return false;
}

int main(){
	memset(arr,0,sizeof(arr));
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	memset(seg,0,sizeof(seg));
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin >> arr[i][j];
			int v=arr[i][j];
			if(v){
				row[i][v-1] = 1;
				col[j][v-1] = 1;
				int s = int(i/3)*3+int(j/3);
				seg[s][v-1] = 1;
			}	
		}
	}
	solve(0);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)	cout << arr[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}