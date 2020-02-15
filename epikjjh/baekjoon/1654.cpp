#include <bits/stdc++.h>

using namespace std;

int main(){
	int k,n;
	long long l=1,h=0;
	cin >> k >> n;
	vector<int> v(k);
	for(int &p: v){
		cin >> p;
		h = (h>p) ? h : p;
	}
	h++;
	while(l+1<h){
		long long mid = (l+h)/2;
		long long cnt=0;
		for(int &p: v)	cnt += p/mid;
		if(cnt>=n)	l = mid;
		else	h = mid;
	}
	cout << l << endl;
	
	return 0;
}