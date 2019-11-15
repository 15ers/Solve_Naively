#include <bits/stdc++.h>

using namespace std;

int multiply(int a,int b,int c){
	if(b==1)	return a%c;
	int ret = multiply(a,b/2,c);
	ret = 1LL*ret*ret%c;
	if(b%2)	ret = 1LL*ret*a%c;
	return ret;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int a,b,c;
	long long ret;
	cin >> a >> b >> c;
	ret = multiply(a,b,c);
	cout << ret << endl;
	
	return 0;
}