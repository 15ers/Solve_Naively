#include <bits/stdc++.h>

using namespace std;

int a[12],b[12];
int ret=0;

void iterate(long long as, long long bs, int ind, int n, int h){
	if(ind==n){
		if(as>=h&&bs>=h)	ret++;
		return;
	}
	iterate(as+a[ind],bs,ind+1,n,h);
	iterate(as+a[ind],bs+b[ind],ind+1,n,h);
	iterate(as,bs+b[ind],ind+1,n,h);
}


int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		ret=0;
		int n,h;
		scanf("%d %d", &n,&h);
		for(int j=0;j<n;j++)	scanf("%d",&a[j]);
		for(int j=0;j<n;j++)	scanf("%d",&b[j]);
		iterate(0LL,0LL,0,n,h);
		printf("Case #%d: %d\n",i,ret);
	}
	
	return 0;
}