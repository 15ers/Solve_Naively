#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t,ret;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		if(s.size()==3){
			if(s[1]=='n'&&s[2]=='e' || s[0]=='o'&&s[2]=='e' || s[0]=='o'&&s[1]=='n')	ret = 1;
			else	ret = 2;
		}
		else	ret = 3;
		cout << ret << endl;
	}
	
	return 0;
}