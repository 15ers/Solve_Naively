#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		string s;
		cin >> s;
		vector<int> ang;
		for(int i=0;i<k;i++)	if(s[i]=='A')	ang.push_back(i);
		ang.push_back(k);
		int ret = 0;
		for(int i=1;i<ang.size();i++)	ret = max(ret,ang[i]-ang[i-1]-1);
		cout << ret << endl;
	}
	
	
	return 0;
}