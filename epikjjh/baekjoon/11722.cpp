#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,ret=0;
	cin >> n;
	vector<int> arr(n),dp(n);
	dp[0] = 1;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		for(int j=0;j<i;j++)	dp[i] = max(dp[i],(arr[i]<arr[j])*dp[j]+1);
		ret = max(ret,dp[i]);
	}
	cout << ret << endl;
	
	return 0;
}