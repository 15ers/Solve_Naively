#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	for(int i=1;i<=t;i++){
		int n,ret=0,tmp;
		cin >> n;
		for(int j=0;j<n;j++){
			cin >> tmp;
			ret = max(ret,tmp);
		}
		cout << "Case " << i << ": " << ret << endl;
	}
	
	return 0;
}