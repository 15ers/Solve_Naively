#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t,n=1,l,w,h;
	cin >> t;
	while(t--){
		string ret = "bad";
		cin >> l >> w >> h;
		if(l<=20 && w<=20 && h<=20)	ret = "good";
		cout << "Case " << n++ << ": " << ret << endl;
	}
	
	return 0;
}