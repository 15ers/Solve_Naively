#include <bits/stdc++.h>

using namespace std;

char arr[2187][2187];

void paint(int r, int c, int s){
	if(s==1){
		arr[r][c] = '*';
		return;
	}
	int n_s = s/3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i==1&&j==1)	continue;
			paint(r+i*n_s,c+j*n_s,n_s);
		}
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)	arr[i][j] = ' ';
	}
	paint(0,0,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)	cout << arr[i][j];
		cout << endl;
	}	
	return 0;
}