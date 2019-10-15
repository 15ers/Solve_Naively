#include <bits/stdc++.h>
#define INT(s) (s-'0')
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> dp(n+1);
	if(!INT(s[0])){
		cout << "0" << endl;
		return 0;
	}
	dp[0]=dp[1]=1;
	for(int i=2;i<=n;i++){
		int fi=INT(s[i-2]),se=INT(s[i-1]);
		if(!(fi+se)){
			cout << "0" << endl;
			return 0;
		}
		if(fi){
			if(fi*10+se<=26)	dp[i] += dp[i-2];
		}
		if(se)	dp[i] += dp[i-1];
		dp[i] %= 1000000;
	}
	cout << dp[n] << endl;
	return 0;
}