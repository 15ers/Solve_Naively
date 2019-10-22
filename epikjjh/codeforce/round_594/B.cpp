#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)	cin >> arr[i];
	sort(arr.begin(),arr.end(),greater<int>());
	long long int s=0,e=0;
	for(int i=0;i<n;i++){
		if(i<=(n-1)/2)	s += arr[i];
		else	e += arr[i];
	}
	cout << s*s+e*e << endl;
	return 0;
}