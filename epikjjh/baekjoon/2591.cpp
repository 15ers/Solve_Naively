#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int l=s.size();
	vector<int> dp(l);
	dp[0] = 1;
	dp[1] = (1<=s[0]-'0') ? 1 : 0;
	for(int i=2;i<=l;i++){
		if(1<=s[i-1]-'0')	dp[i] = dp[i-1];
		int tmp = (s[i-2]-'0')*10+s[i-1]-'0';
		if(s[i-2]!='0' && 1<=tmp && tmp<=34)	dp[i] += dp[i-2];
	}
	cout << dp[l] << endl;
	
	return 0;
}