#include <bits/stdc++.h>

using namespace std;

long long dp[91] = {0,1};

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	for(int i=2;i<=90;i++)	dp[i] = dp[i-1]+dp[i-2];
	int n;
	cin >> n;
	cout << dp[n] << endl;
	
	return 0;
}