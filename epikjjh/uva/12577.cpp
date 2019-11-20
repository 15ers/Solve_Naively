#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	string s,ret;
	int t=1;
	while(cin>>s,s!="*"){
		if(s=="Hajj")	ret = "Hajj-e-Akbar";
		else	ret = "Hajj-e-Asghar";
		cout << "Case " << t++ << ": " << ret << endl;
	}
	
	
	return 0;
}