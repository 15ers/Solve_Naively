#include <bits/stdc++.h>

using namespace std;

int dp[501][501],arr[501][501];

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,ret=0;
	cin >> n;
	for(int i=1;i<=n;i++)	for(int j=1;j<=i;j++)	cin >> arr[i][j];
	ret = dp[1][1] = arr[1][1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j==1)	dp[i][j] = dp[i-1][j]+arr[i][j];
			else if(j==i)	dp[i][j] = dp[i-1][j-1]+arr[i][j];
			dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+arr[i][j];
			ret = max(ret,dp[i][j]);
		}
	}
	cout << ret << endl;
	
	return 0;
}