#include <bits/stdc++.h>

using namespace std;

string arr[64];
string ret = "";

bool check(int r, int c, int size){
	int st = arr[r][c];
	for(int i=r;i<r+size;i++){
		for(int j=c;j<c+size;j++)	if(st!=arr[i][j])	return false;
	}
	return true;
}

void quad_tree(int r, int c, int size){
	if(check(r,c,size)){
		ret += arr[r][c];
		return;
	}
	int n_s = size/2;
	ret += "(";
	for(int i=0;i<4;i++)	quad_tree(r+i/2*n_s,c+i%2*n_s,n_s);
	ret += ")";
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	quad_tree(0,0,n);
	cout << ret << endl;
	
	return 0;
}