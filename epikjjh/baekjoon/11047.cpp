#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,k,ret=0;
	int arr[10] = {0};
	cin >> n >> k;
	for(int i=0;i<n;i++)	cin >> arr[i];
	sort(arr,arr+n,greater<int>());
	for(int i=0;i<n;i++){
		if(arr[i]>k)	continue;
		ret += k/arr[i];
		k %= arr[i];
	}
	cout << ret << endl;
	
	return 0;
}