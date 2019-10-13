#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	vector<int> m(n),dp(n);
	for(int i=0;i<n;i++)	cin >> m[i];
	dp[0] = m[0], dp[1] = dp[0]+m[1], dp[2] = max(dp[1],m[2]+max(m[0],m[1]));
	for(int i=3;i<n;i++){
		dp[i] = max(dp[i-2],m[i-1]+dp[i-3])+m[i];
		dp[i] = max(dp[i],dp[i-1]);
	}
	cout << dp[n-1] << endl;
	
	return 0;
}