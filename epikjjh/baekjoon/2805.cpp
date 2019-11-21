#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,l=0,h=0;
	cin >> n >> m;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		h = max(h,arr[i]);
	}
	while(l+1<h){
		int mid = (l+h)/2;
		long long s = 0;
		for(int i=0;i<n;i++)	if(arr[i]>mid)	s += arr[i]-mid;
		if(s>=m)	l = mid;
		else	h = mid;
	}
	cout << l << endl;
	
	return 0;
}