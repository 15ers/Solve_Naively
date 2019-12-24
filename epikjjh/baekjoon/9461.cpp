#include <bits/stdc++.h>

using namespace std;

long long int dp[101]={0,1,1};

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	for(int i=3;i<=100;i++)	dp[i] = dp[i-2]+dp[i-3];
	int n,i;
	cin >> n;
	while(n--){
		cin >> i;
		cout << dp[i] << endl;
	}
	return 0;
}