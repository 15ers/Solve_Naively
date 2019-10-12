#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		if(i==n-1){
			for(int j=0;j<2*n-1;j++)	cout << "*";
			cout << endl;
		}
		else{
			for(int j=0;j<n-i-1;j++)	cout << " ";
			for(int j=0;j<2*i+1;j++){
				if(j==0 || j==2*i)	cout << "*";
				else	cout << " ";
			}
			cout << endl;
		}
	}
}