#include <bits/stdc++.h>

using namespace std;

void swap(char& from, char& to){
	char tmp=from;
	from = to;
	to = tmp;
}

int check(const vector<string>& arr){
	int n=arr.size(),row=0,col=0;
	for(int i=0;i<n;i++){
		int tmp = 1;
		for(int j=1;j<n;j++){
			if(arr[i][j]==arr[i][j-1])	tmp++;
			else{
				row = max(row,tmp);
				tmp = 1;
			}
		}
		row = max(row,tmp);
	}
	for(int j=0;j<n;j++){
		int tmp = 1;
		for(int i=1;i<n;i++){
			if(arr[i][j]==arr[i-1][j])	tmp++;
			else{
				col = max(col,tmp);
				tmp = 1;
			}
		}
		col = max(col,tmp);
	}
	return max(row,col);
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	
	int n,ret=0;
	cin >> n;
	vector<string> arr(n);
	for(int i=0;i<n;i++)	cin >> arr[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<2;k++){
				int nx=i+1-k, ny=j+k;
				if(nx<0 || nx>=n || ny<0 || ny>=n)	continue;
				if(arr[i][j]==arr[nx][ny])	continue;
				swap(arr[i][j],arr[nx][ny]);
				ret = max(ret,check(arr));
				swap(arr[nx][ny],arr[i][j]);
			}
		}
	}
	cout << ret << endl;
	
	return 0;
}