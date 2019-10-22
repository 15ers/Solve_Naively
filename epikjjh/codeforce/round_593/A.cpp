#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int a,b,c,i,j,ret=0;
		cin >> a >> b >> c;
		for(i=b;i>=0;i--)	if(2*i<=c)	break;
		ret += 3*i;
		for(j=(b-i)/2;j>=0;j--)	if(a>=j)	break;
		ret += 3*j;
		cout << ret << endl;
	}
	
	return 0;
}