#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int dp[201][201]={0},n,k;
	cin >> n >> k;
	for(int i=0;i<=n;i++)	dp[1][i] = 1;
	for(int i=2;i<=k;i++){
		for(int j=0;j<=n;j++){
			for(int l=0;l<=j;l++)	dp[i][j] = (dp[i][j]+dp[i-1][j-l])%MOD;
		}
	}
	cout << dp[k][n] << endl;
	
	return 0;
}