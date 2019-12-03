#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int b,n;
	while(cin>>b>>n,b&&n){
		vector<int> r(b+1);
		for(int i=1;i<=b;i++)	cin >> r[i];
		for(int i=0;i<n;i++){
			int d,c,v;
			cin >> d >> c >> v;
			r[d] -= v;
			r[c] += v;
		}
		bool flag = true;
		for(int i=1;i<=b;i++)	if(r[i]<0)	flag = false;
		if(flag)	cout << "S" << endl;
		else	cout << "N" << endl;
	}
	
	return 0;
}