#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int a,b,c,r;
		cin >> a >> b >> c >> r;
		if(b<a)	swap(a,b);
		int c_l=c-r,c_r=c+r;
		if(c_l<=a && b<=c_r)	cout << 0 << endl;
		else if(c_r<=a || b<=c_l)	cout << b-a << endl;
		else{
			if(a<=c_l && c_r<=b)	cout << c_l-a+b-c_r << endl;
			else if(c_l<=a&&c_r<=b)	cout << b-c_r << endl;
			else	cout << c_l-a << endl;
		}
	}
	
	return 0;
}