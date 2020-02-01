#include <bits/stdc++.h>

using namespace std;

int dp[100001];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		int n,x,ret=0;
		string s;
		scanf("%d %d",&n,&x);
		cin >> s;
		dp[0] = 0;
		bool inf=false;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0')	dp[i] += dp[i-1]+1;
			else dp[i] += dp[i-1]-1;
			if(dp[i]==x)	inf=true;
		}
		if(!dp[n]){
			if(inf)	ret=-1;
			else{
				if(!x)	ret=1;
				else	ret=0;
			}
		}
		else{
			if(!x)	ret++;
			if(dp[n]>0){				
				for(int i=1;i<=n;i++){
					if(dp[i]==x)	ret++;
					if(dp[i]<x && (x-dp[i])%dp[n]==0)	ret++;
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(dp[i]==x)	ret++;
					if(dp[i]>x && (dp[i]-x)%dp[n]==0)	ret++;
				}
			}
		}
		printf("%d\n",ret);
	}
	
	return 0;
}