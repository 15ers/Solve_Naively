#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	long long l,n,r_f,r_b,d,x,c;
	long long arr[1000001] = {0};
	cin >> l >> n >> r_f >> r_b;
	d = r_f - r_b;
	for(int i=0;i<n;i++){
		cin >> x >> c;
		arr[x] = c;
	}
	int max_c=-1;
	for(int i=1000000;i>=1;i--){
		if(!arr[i])	continue;
		if(arr[i]>max_c)	max_c = arr[i];
		else	arr[i] = 0;
	}
	int prev=0;
	long long ret=0;
	for(int i=0;i<=1000000;i++){
		if(arr[i]){
			ret += arr[i]*(i-prev)*d;
			prev = i;
		}
	}
	cout << ret << endl;
	
	return 0;
}