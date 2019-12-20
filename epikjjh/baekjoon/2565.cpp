#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,a,b,ret=0;
	cin >> n;
	vector<pair<int,int> > arr(n);
	vector<int> dp(n);
	for(int i=0;i<n;i++)	cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		if(!dp[i])	dp[i] = 1;
		for(int j=0;j<i;j++)	if(arr[j].second<arr[i].second)	dp[i] = max(dp[i],dp[j]+1);
		ret = max(ret,dp[i]);
	}
	cout << n-ret << endl;
	
	return 0;
}