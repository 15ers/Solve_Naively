#include <bits/stdc++.h>

using namespace std;

long long solve(){
	int n;
	long long m;
	scanf("%d %lld",&n,&m);
	vector<long long> arr(n);
	for(int i=0;i<n;i++)	scanf("%lld", &arr[i]);
	long long c=0;
	for(int bit=50;bit>=0;bit--){
		int cnt=0;
		for(long long x: arr)	if(x&(1LL<<bit))	cnt++;
		c += (1LL<<bit)*min(cnt,n-cnt);
	}
	if(c>m)	return -1;
	long long k=0;
	for(int bit=50;bit>=0;bit--){
		int cnt=0;
		for(long long x: arr)	if(x&(1LL<<bit))	cnt++;
		long long cand = c - (1LL<<bit)*min(cnt,n-cnt);
		if(cand+(1LL<<bit)*(n-cnt)<=m){
			k += 1LL<<bit;
			c = cand+(1LL<<bit)*(n-cnt);
		}
		else	c = cand+(1LL<<bit)*cnt;
	}
	return k;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)	printf("Case #%d: %lld\n",i,solve());
	
	return 0;
}