#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int x[1001]={0},y[1001]={0},r_x,r_y;
	for(int i=0;i<3;i++){
		int c_x,c_y;
		cin >> c_x >> c_y;
		x[c_x]++, y[c_y]++;
	}
	for(int i=1;i<=1000;i++){
		if(x[i]==1)	r_x = i;
		if(y[i]==1)	r_y = i;
	}
	cout << r_x << " " << r_y << endl;
	
	return 0;
}