#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> lava;

int main(){
	int n,q,r,c;
	cin >> n >> q;
	lava.resize(2,vector<int>(n));
	int cnt=0;
	while(q--){
		cin >> r >> c; r--; c--;
		int d = lava[r][c]==1 ? -1 : 1;
		lava[r][c] ^= 1;
		for(int dc=-1;dc<=1;dc++){
			if(c+dc<0 || c+dc>=n)	continue;
			if(lava[1-r][c+dc]==1)	cnt += d;
		}
		cout << (cnt==0 ? "Yes" : "No") << endl;
	}
	
	return 0;
}