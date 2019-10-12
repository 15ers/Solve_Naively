#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,t,min=1000000,max=-1000000;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> t;
		min = (t<min) ? t : min;
		max = (t>max) ? t : max;
	}
	cout << min << " " << max << endl;
	return 0;
}