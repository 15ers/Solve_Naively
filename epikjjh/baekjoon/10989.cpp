#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,tmp;
	scanf("%d",&n);
	int arr[10001] = {0};
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		arr[tmp]++;
	}
	for(int i=1;i<=10000;i++){
		if(arr[i])	for(int j=0;j<arr[i];j++)	printf("%d\n",i);
	}
	return 0;
}