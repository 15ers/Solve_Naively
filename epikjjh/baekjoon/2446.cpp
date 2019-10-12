#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<2*n-1;i++){
		int s = (i<n) ? 2*(n-i)-1 : 1+2*(i-n+1);
		int p = (2*n-1-s)/2;
		for(int j=0;j<p;j++)	cout << " ";
		for(int j=0;j<s;j++)	cout << "*";
		cout << endl;
	}
	
	return 0;
}