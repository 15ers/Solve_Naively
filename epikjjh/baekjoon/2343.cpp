#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,l=0,h=0;
	cin >> n >> m;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		h += arr[i];
		l = max(l,arr[i]);
	}
	l--;
	while(l+1<h){
		int mid=(l+h)/2,b=1,s=0;
		for(int i=0;i<n;i++){
			if(s+arr[i]>mid){
				s=0;
				b++;
			}
			s += arr[i];
		}
		if(b>m)	l = mid;
		else	h = mid;
	}
	cout << h << endl;
	
	return 0;
}