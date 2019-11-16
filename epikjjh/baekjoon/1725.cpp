#include <bits/stdc++.h>

using namespace std;

int arr[100000];

int hist(int s, int e){
	if(s+1==e)	return arr[s];
	int mid = (s+e)/2;
	int ret = max(hist(s,mid),hist(mid,e));
	int w=1,h=arr[mid],l=mid,r=mid;
	while(s<l || r<e-1){
		if(r<e-1 && (s==l||arr[r+1]>arr[l-1]))	h = min(h,arr[++r]);
		else	h = min(h,arr[--l]);
		ret = max(ret,++w*h);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)	cin >> arr[i];
	cout << hist(0,n) << endl;
	
	return 0;
}