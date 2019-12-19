#include <bits/stdc++.h>

using namespace std;

int dp[101][100001];
int w[100],v[100];

int knapsack(int index, int weight){
	if(index<0)	return 0;
	if(dp[index][weight]>0)	return dp[index][weight];
	if(w[index]>weight)	return knapsack(index-1,weight);
	return dp[index][weight] = max(knapsack(index-1,weight-w[index])+v[index], knapsack(index-1,weight));
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	memset(dp,-1,sizeof(dp));
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++)	cin >> w[i] >> v[i];
	cout << knapsack(n-1,k) << endl;

	return 0;
}