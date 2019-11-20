#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t,n=1;
	int arr[3];
	cin >> t;
	while(t--){
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr,arr+3);
		cout << "Case " << n++ << ": " <<arr[1] << endl;
	}
	
	return 0;
}