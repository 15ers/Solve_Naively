#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n),dp(n);
	int ret = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		dp[i] = arr[i];
		for(int j=0;j<i;j++)	if(arr[i]>arr[j])	dp[i] = max(dp[i],dp[j]+arr[i]);
		ret = max(ret,dp[i]);
	}
	cout << ret << endl;
	
	return 0;
}