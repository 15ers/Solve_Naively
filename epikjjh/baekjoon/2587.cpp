#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> arr(5);
	int s=0;
	for(int i=0;i<5;i++){
		cin >> arr[i];
		s += arr[i];
	}
	sort(arr.begin(),arr.end());
	cout << s/5 << endl;
	cout << arr[2] << endl;
	
	return 0;
}