#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t,n,ret;
	cin >> t;
	while(t--){
		cin >> n;
		ret = (n*567/9+7492)*235/47-498;
		if(ret<0)	ret *= -1;
		cout << ret%100/10 << endl;
	}

	return 0;
}