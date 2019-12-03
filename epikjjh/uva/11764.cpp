#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	for(int j=1;j<=t;j++){
		int n,prev,cur,h=0,l=0;
		cin >> n;
		cin >> prev;
		for(int i=1;i<n;i++){
			cin >> cur;
			if(prev<cur)	h++;
			else if(prev>cur)	l++;
			prev = cur;
		}
		cout << "Case " << j << ": " << h << " " << l << endl;
	}
	
	return 0;
}