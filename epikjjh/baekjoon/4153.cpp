#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int a,b,c;
	int arr[3];
	while(cin>>a>>b>>c,a&&b&&c){
		arr[0]=a,arr[1]=b,arr[2]=c;
		sort(arr,arr+3);
		if(arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2])	cout << "right" << endl;
		else	cout << "wrong" << endl;
	}
	
	return 0;
}