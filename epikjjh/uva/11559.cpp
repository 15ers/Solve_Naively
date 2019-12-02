#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,b,w,h,ret,a,p;
	while(cin>>n>>b>>h>>w){
		ret=b+1;
		while(h--){
			bool flag = false;
			cin >> p;
			for(int i=0;i<w;i++){
				cin >> a;
				if(a>=n)	flag = true;
			}
			if(flag)	ret = min(ret,n*p);
		}
		if(ret>b)	cout << "stay home" << endl;
		else	cout << ret << endl;
	}
	
	return 0;
}