#include <bits/stdc++.h>

using namespace std;

int n,p,k;
vector<int> arr;

int find(){
	vector<int> dp(n+1);
	dp[0] = 0;
	for(int i=1;i<k;i++)	dp[i] = dp[i-1]+arr[i-1];
	for(int i=k;i<=n;i++)	dp[i] = dp[i-k]+arr[i-1];
	int ret=0;
	for(int i=0;i<=n;i++)	if(p>=dp[i])	ret=i;
	return ret;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&p,&k);
		arr.resize(n);
		for(int &i: arr)	cin >> i;
		sort(arr.begin(),arr.end());
		cout << find() << endl;
	}
	
	return 0;
}