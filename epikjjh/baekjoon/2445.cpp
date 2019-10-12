#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	string star="*",space=" ";
	cin >> n;
	for(int i=0;i<2*n-1;i++){
		int s = (i<n) ? i+1 : 2*n-1-i;
		int p = 2*(n-s);
		for(int j=0;j<s;j++) cout << "*";
		for(int j=0;j<p;j++) cout << " ";
		for(int j=0;j<s;j++) cout << "*";
		cout << endl;
	}
}