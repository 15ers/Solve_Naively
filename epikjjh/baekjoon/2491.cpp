#include <bits/stdc++.h>

using namespace std;

int arr[100000];
int dp_min[100000];
int dp_max[100000];

int main(){
	int n,ret=1;
	cin >> n;
	for(int i=0;i<n;i++)	cin >> arr[i];
	dp_min[0] = dp_max[0] = 1;
	for(int i=1;i<n;i++){
		if(arr[i-1]<=arr[i])	dp_max[i] = dp_max[i-1]+1;
		else	dp_max[i] = 1;
		if(arr[i-1]>=arr[i])	dp_min[i] = dp_min[i-1]+1;
		else	dp_min[i] = 1;
		ret = max(ret,max(dp_max[i],dp_min[i]));
	}
	cout << ret << endl;
	
	return 0;
}