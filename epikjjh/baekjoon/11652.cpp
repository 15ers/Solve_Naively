#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,j,max_cnt=0;
	long long int arr[1000000],max_num,num;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	scanf("%lld",arr+i);
	sort(arr,arr+n);
	max_num = arr[0];
	for(int i=0;i<n;){
		num = arr[i];
		for(j=i+1;j<n;j++){
			if(arr[i]==arr[j])	continue;
			else	break;
		}
		max_num = (j-i)>max_cnt ? num : max_num;
		max_cnt = max(max_cnt,j-i);
		i = j;
	}
	printf("%lld\n",max_num);
	
	return 0;
}