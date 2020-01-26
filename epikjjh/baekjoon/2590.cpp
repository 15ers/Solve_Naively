#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c,d,e,f,ret=0;
	cin >> a >> b >> c >> d >> e >> f;
	ret += d+e+f;
	a -= e*11;
	b -= d*5;
	ret += (c%4) ? c/4+1 : c/4;
	switch(c%4){
		case 1:
			b -= 5;
			a -= 7;
			break;
		case 2:
			b -= 3;
			a -= 6;
			break;
		case 3:
			b -=1;
			a -=5;
			break;
		default:
			break;
	}
	if(b<0)	a -= abs(b)*4;
	else{
		ret += (b%9) ? b/9+1 : b/9;
		if(b%9)	a -= 36-(b%9)*4;
	}
	if(a>0)	ret += (a%36) ? a/36+1 : a/36;
	cout << ret << endl;
	
	return 0;
}