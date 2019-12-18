#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	string s,tmp= "";
	cin >> s;
	int ret=0,neg=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='-' || s[i]=='+' || s[i]=='\0'){
			if(neg)	ret -= stoi(tmp);
			else	ret += stoi(tmp);
			if(s[i]=='-')	neg = 1;
			tmp = "";
		}
		else	tmp += s[i];
	}
	cout << ret << endl;
	
	return 0;
}