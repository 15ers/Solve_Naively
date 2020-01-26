#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)	arr[i] = i+1;
	for(int i=0;i<n;i++){
		int t,tmp;
		cin >> t;
		tmp = arr[i]; 
		for(int j=i;j>i-t;j--)	arr[j] = arr[j-1];
		arr[i-t] = tmp;
	}
	for(int i: arr)	cout << i << " ";
	cout << endl;
	
	return 0;
}