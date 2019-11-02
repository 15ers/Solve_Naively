#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,l;
	cin >> n >> l;
	int arr[1000] = {0}, ret = 0;
	for(int i=0;i<n;i++)	cin >> arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		if(!arr[i])	continue;
		double f = arr[i] - 0.5 + l;
		for(int j=0;j<n;j++){
			if(f>=arr[j]+0.5)	arr[j] = 0;
			else	break;
		}
		ret++;
	}
	cout << ret << endl;
	
	return 0;
}