#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t,a,b,n,m;
	cin >> t;
	while(t--){
		cin >> a >> b;
		n = (a-2)%3 ? (a-2)/3+1 : (a-2)/3;
		m = (b-2)%3 ? (b-2)/3+1 : (b-2)/3;
		cout << n*m << endl;
	}
	
	return 0;
}