#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		int cur,sub,path;
		cin >> n;
		int arr[2][100001];
		int dp[2][100001] = {0};
		for(int i=1;i<=2*n;i++){
			if(i<=n)	cin >> arr[0][i];
			else	cin >> arr[1][i-n];
		}
		dp[0][1] = arr[0][1], dp[1][1] = arr[1][1];
		for(int i=2;i<=n;i++){
			dp[0][i] = max(dp[1][i-1],dp[1][i-2])+arr[0][i];
			dp[1][i] = max(dp[0][i-1],dp[0][i-2])+arr[1][i];
		}
		cout << max(dp[0][n],dp[1][n]) << endl;
	}
	
	return 0;
}