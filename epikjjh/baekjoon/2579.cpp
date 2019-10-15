#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	vector<int> step(n),dp(n);
	for(int i=0;i<n;i++)	cin >> step[i];
	dp[0] = step[0];
	if(n>1)	dp[1] = step[0]+step[1];
	if(n>2)	dp[2] = max(step[1]+step[2],step[0]+step[2]);
	for(int i=3;i<n;i++)	dp[i] = step[i] + max(step[i-1]+dp[i-3],dp[i-2]);
	cout << dp[n-1] << endl;
	
	return 0;
}