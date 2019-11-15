#include <bits/stdc++.h>
#define IMP 987654321

using namespace std;

int n, w[16][16], dp[16][1<<16];

int tsp(int cur, int visited){
	int &ret = dp[cur][visited];
	if(ret != -1)	return ret;
	if(visited==(1<<n)-1)	return !w[cur][0] ? IMP : w[cur][0];
	ret = IMP;
	for(int i=0;i<n;i++){
		if(visited&(1<<i) || !w[cur][i])	continue;
		ret = min(ret, tsp(i,visited|(1<<i))+w[cur][i]);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin >> n;
	for(int i=0;i<n;i++)	for(int j=0;j<n;j++)	cin >> w[i][j];
	memset(dp,-1,sizeof(dp));
	cout << tsp(0,1) << endl;
	
	return 0;
}