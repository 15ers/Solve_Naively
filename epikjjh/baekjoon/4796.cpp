#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int l,p,v;
	for(int i=1;;i++){
		cin >> l >> p >> v;
		if(!l && !p && !v)	break;
		int ret = (v/p)*l;
		ret += min((v%p),l); 
		cout << "Case " << i << ": " << ret << endl;
	}
	
	return 0;
}