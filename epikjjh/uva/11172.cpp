#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t,a,b;
	char ret;
	cin >> t;
	while(t--){
		cin >> a >> b;
		if(a==b)	ret = '=';
		else	ret = (a>b) ? '>' : '<';
		cout << ret << endl;
	}
	
	return 0;
}