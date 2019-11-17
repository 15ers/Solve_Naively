#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	string s;
	bool flag = false;
	while(getline(cin,s)){
		string ret="";
		for(int i=0;i<s.size();i++){
			if(s[i]=='"'){
				if(flag){
					ret += "''";
					flag = false;
				}
				else{
					ret += "``";
					flag = true;
				}
			}
			else	ret += s[i];
		}
		cout << ret << endl;
	}
	
	return 0;
}