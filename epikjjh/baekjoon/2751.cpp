#include <bits/stdc++.h>

using namespace std;

void merge(int* arr, int left, int mid, int right){
	vector<int> tmp;
	int li = left, ri = mid+1;
	while(li<=mid && ri<=right){
		if(arr[li]<arr[ri])	tmp.push_back(arr[li++]);
		else	tmp.push_back(arr[ri++]);
	}
	if(li<=mid)	while(li<=mid)	tmp.push_back(arr[li++]);
	else	while(ri<=right)	tmp.push_back(arr[ri++]);
	for(int i=0;i<tmp.size();i++)	arr[left+i] = tmp[i];
}

void merge_sort(int* arr, int left, int right){
	if(left<right){
		int mid = (left+right)/2;
		merge_sort(arr,left,mid);
		merge_sort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}

int main(){
	int n;
	int arr[1000000];
	scanf("%d",&n);
	for(int i=0;i<n;i++)	scanf("%d",arr+i);
	merge_sort(arr,0,n-1);
	for(int i=0;i<n;i++)	printf("%d\n",arr[i]);
	
	return 0;
}