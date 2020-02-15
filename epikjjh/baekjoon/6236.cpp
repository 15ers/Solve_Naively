#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> v(n);
	int l=0,h=0,max_v=0;
	for(int &p: v){
		cin >> p;
		max_v = max(max_v,p);
		h += p;
	}
	while(l+1<h){
		int mid = (l+h)/2;
		int cnt=1;
		if(mid<max_v)	cnt = m+1;
		else{
			int s=0;
			for(int p: v){
				s+=p;
				if(s>mid){
					cnt++;
					s=p;
				}
			}
		}
		if(cnt<=m)	h = mid;
		else	l = mid;
	}
	cout << h << endl;
	
	return 0;
}