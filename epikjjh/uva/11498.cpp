#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t,n,m,x,y;
	while(cin >> t, t){
		cin >> n >> m;
		while(t--){
			cin >> x >> y;
			if(x==n || y==m)	cout << "divisa" << endl;
			else{
				if(x>n){
					if(y>m)	cout << "NE" << endl;
					else	cout << "SE" << endl;
				}
				else{
					if(y>m)	cout << "NO" << endl;
					else	cout << "SO" << endl;
				}
			}
		}
	}
	
	return 0;
}