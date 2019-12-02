#include <bits/stdc++.h>

using namespace std;

int f(int n){
	if(n<10)	return n;
	int s=0;
	while(n){
		s += n%10;
		n /= 10;
	}
	return f(s);
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	while(cin>>n, n)	cout << f(n) << endl;
	
	return 0;
}