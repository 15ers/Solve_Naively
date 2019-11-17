#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int a,b,c,d;
	while(cin>>a>>b>>c>>d,a||b||c||d){
		int ret = 360*3;
		if(a<b)	ret += (a+40-b)*9;
		else	ret += (a-b)*9;
		if(b>c)	ret += (c+40-b)*9;
		else	ret += (c-b)*9;
		if(c<d)	ret += (c+40-d)*9;
		else	ret += (c-d)*9;
		cout << ret << endl;
	}
	
	return 0;
}