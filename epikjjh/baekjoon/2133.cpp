#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	vector<int> dp(n+1);
	dp[0] = 1;
	for(int i=2;i<=n;i+=2){
		dp[i] = dp[i-2]*3;
		for(int j=4;j<=i;j+=2)	dp[i] += dp[i-j]*2;
	}
	cout << dp[n] << endl;
	
	return 0;
}