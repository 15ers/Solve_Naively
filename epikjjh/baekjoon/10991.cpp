#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=i;j<n-1;j++)	cout << " ";
		for(int j=0;j<=i;j++){
			if(j==i)	cout << "*" << endl;
			else	cout << "* ";
		}
	}
	
	return 0;
}