#include <bits/stdc++.h>

using namespace std;

int n;
int init[10000],fin[10000],dp[10000][10],dir[10000][10];

int func(int l, int k){
	if(l==n)	return 0;
	int &ret=dp[l][k];
	if(ret!=-1)	return dp[l][k];
	int cur=(init[l]+k)%10;
	int left=func(l+1,(k+fin[l]-cur+10)%10)+(fin[l]-cur+10)%10;
	int right=func(l+1,k)+(cur-fin[l]+10)%10;
	if(left<right)	dir[l][k] = (fin[l]-cur+10)%10;
	else	dir[l][k] = -1*(cur-fin[l]+10)%10;
	
	return ret = min(left,right);
}
void pfunc(int l, int k){
	if(l==n)	return;
	if(dir[l][k])	cout << l+1 << " " << dir[l][k] << endl;
	if(dir[l][k]<0)	pfunc(l+1,k);
	else	pfunc(l+1,(k+dir[l][k])%10);
}


int main(){
	cin >> n;
	for(int i=0;i<n;i++)	scanf("%1d",&init[i]);
	for(int i=0;i<n;i++)	scanf("%1d",&fin[i]);
	memset(dp,-1,sizeof(dp));
	cout << func(0,0) << endl;
	pfunc(0,0);
	return 0;
}