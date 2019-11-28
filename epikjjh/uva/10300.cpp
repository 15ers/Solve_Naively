#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,a,b,c,ret=0;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a >> b >> c;
			ret += a*c;
		}
		cout << ret << endl;
	}
	
	return 0;
}