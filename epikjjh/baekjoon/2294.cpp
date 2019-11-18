#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int dp[101][10001];
int coin[101];
int n,k;

int top_down(int s,int k){
	if(s==n)	return (k==0) ? 0 : INF;
	if(dp[s][k]!=-1)	return dp[s][k];
	int ret = top_down(s+1,k);
	if(coin[s]<=k)	ret = min(ret,top_down(s,k-coin[s])+1);
	return dp[s][k] = ret;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> k;
	for(int i=0;i<=n;i++)	for(int j=0;j<=k;j++)	dp[i][j] = -1;
	for(int i=0;i<n;i++)	cin >> coin[i];
	int ret = top_down(0,k);
	if(ret==INF)	cout << -1 << endl;
	else	cout << ret << endl;
	
	return 0;
}