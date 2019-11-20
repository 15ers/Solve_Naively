#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,t=1;
	while(cin>>n,n){
		int a=0,b=0,x;
		for(int i=0;i<n;i++){
			cin >> x;
			if(x)	a++;
			else	b++;
		}
		cout << "Case " << t++ << ": "<<  a-b << endl;
	}
	
	return 0;
}