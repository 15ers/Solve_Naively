#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	string s;
	int t=1;
	while(cin>>s,s!="#"){
		string ret;
		if(s=="HELLO")	ret = "ENGLISH";
		else if(s=="HOLA")	ret = "SPANISH";
		else if(s=="HALLO")	ret = "GERMAN";
		else if(s=="BONJOUR")	ret = "FRENCH";
		else if(s=="CIAO")	ret = "ITALIAN";
		else if(s=="ZDRAVSTVUJTE")	ret = "RUSSIAN";
		else	ret = "UNKNOWN";
		cout << "Case " << t++ << ": " << ret << endl;
	}
	
	return 0;
}