#include <bits/stdc++.h>

using namespace std;

int n,dp[101];
string s;
vector<string> v;

int dfs(int ind){
	int &ret=dp[ind];
	if(ret!=-1)	return ret;
	if(ind==s.size())	return ret=1;
	ret=0;
	for(int i=0;i<n;i++){
		string tmp=v[i];
		if(s.size()<ind+tmp.size())	continue;
		bool flag=true;
		for(int j=0;j<tmp.size();j++)	if(s[ind+j]!=tmp[j])	flag = false;
		if(flag)	ret |= dfs(ind+tmp.size());
	}
	
	return ret;
}

int main(){
	cin >> s >> n;
	v.resize(n);
	for(auto &p: v)	cin >> p;
	memset(dp,-1,sizeof(dp));
	cout << dfs(0) << endl;
	
	return 0;
}