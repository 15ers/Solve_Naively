#include <bits/stdc++.h>

using namespace std;

int dp[30] = {1,1,2};

int main(){
	int d,k;
	for(int i=3;i<30;i++)	dp[i] = dp[i-1]+dp[i-2];
	cin >> d >> k;
	int a=dp[d-3],b=dp[d-2];
	for(int i=k/b;i>=1;i--){
		if(!((k-b*i)%a)){
			int ret1=i,ret2=(k-b*i)/a;
			cout << ret2 << endl;
			cout << ret1 << endl;
			break;
		}
	}
	return 0;
}