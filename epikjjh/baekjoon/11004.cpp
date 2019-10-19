#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k,arr[5000000];
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)	scanf("%d",arr+i);
	sort(arr,arr+n);
	printf("%d\n",arr[k-1]);
	return 0;
}