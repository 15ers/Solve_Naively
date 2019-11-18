#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)	cin >> arr[i];
		sort(arr.begin(),arr.end());
		cout << 2*(arr[n-1]-arr[0]) << endl;
	}
	
	return 0;
}