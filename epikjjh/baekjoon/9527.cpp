#include <bits/stdc++.h>

using namespace std;

long long pow2(int n){
	if(n<0)	return 0LL;
	long long ret=1;
	while(n--)	ret<<=1;
	return ret;
}

long long cnt(long long n){
	if(n==0)	return 0;
	long long tmp=n;
	int len=0;
	while(tmp>>=1)	len++;
	long long msb = ((1LL<<len)^n)+1;
	long long lower = len*pow2(len-1);
	long long remain = cnt((1LL<<len)^n);
	return msb+lower+remain;
}

int main(){
	long long a,b;
	cin >> a >> b;
	cout << cnt(b)-cnt(a-1) << endl;
	return 0;
}