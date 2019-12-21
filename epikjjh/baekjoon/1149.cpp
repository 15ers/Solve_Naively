#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int dp[1000][3];
int arr[1000][3];

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)	cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	dp[0][0] = arr[0][0], dp[0][1] = arr[0][1], dp[0][2] = arr[0][2];
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			dp[i][j] = INF;
			for(int k=0;k<3;k++)	if(j!=k)	dp[i][j] = min(dp[i][j], dp[i-1][k]+arr[i][j]);
		}
	}
	cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])) << endl;
	
	return 0;
}