#include <bits/stdc++.h>

using namespace std;

int arr[2187][2187] = {0};
int ret[3] = {0};

bool check(int r,int c,int size){
	int st = arr[r][c];
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)	if(st!=arr[r+i][c+j])	return false;
	}
	if(st<0)	ret[st+3]++;
	else	ret[st]++;
	return true;
}

void split(int r, int c, int size){
	if(check(r,c,size))	return;
	int n_s = size/3;
	for(int i=0;i<9;i++)	split(r+n_s*(i/3),c+n_s*(i%3),n_s);
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)	cin >> arr[i][j];
	}
	split(0,0,n);
	cout << ret[2] << "\n" << ret[0] << "\n" << ret[1] << endl;
	return 0;
}