#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,ret=0;
	cin >> n;
	vector<int> arr(n),dp(n);
	for(int i=0;i<n;i++)	cin >> arr[i];
	dp[0] = ret = arr[0];
	for(int i=1;i<n;i++){
		dp[i] = max(arr[i],dp[i-1]+arr[i]);
		ret = max(ret,dp[i]);	
	}
	cout << ret << endl;
	
	return 0;
}