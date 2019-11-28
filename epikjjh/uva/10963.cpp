#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int w,a,b,diff=-1;
		bool flag = true;
		cin >> w;
		for(int i=0;i<w;i++){
			cin >> a >> b;
			if(diff==-1)	diff = abs(a-b);
			if(diff!=abs(a-b))
				flag = false;
		}
		if(flag)	cout << "yes" << endl;
		else	cout << "no" << endl;
		if(t>0)	cout << endl;
	}
	
	return 0;
}