#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,ret=0;
	
	cin >> n;
	int arr[100][100];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		for(int j=x;j<x+10;j++){
			for(int k=y;k<y+10;k++)	arr[k][j] = 1;
		}
	}
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++)	if(arr[i][j])	ret++;
	}
	cout << ret << endl;
	
	return 0;
}