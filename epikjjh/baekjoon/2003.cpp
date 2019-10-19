#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,arr[10000],s=0,e=0,ps=0,ret=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)	scanf("%d",arr+i);
	while(1){
		if(ps>=m)	ps -= arr[s++];
		else{
			if(e==n)	break;
			else	ps += arr[e++];
		}
		if(ps==m)	ret++;
	}
	printf("%d\n",ret);
	
	return 0;
}