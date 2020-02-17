#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int func(int n, int k){
	if(!k || n==k)	return 1;
	int &ret=dp[n][k];
	if(ret!=-1)	return ret;
	return ret = (func(n-1,k)+func(n-1,k-1))%10007;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n,k;
	cin >> n >> k;
	cout << func(n,k) << endl;
	
	return 0;
}