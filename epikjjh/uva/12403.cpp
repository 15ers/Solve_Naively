#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t,n,ret=0;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		if(s=="donate"){
			cin >> n;
			ret += n;
		}
		else	cout << ret << endl;
	}
	
	return 0;
}