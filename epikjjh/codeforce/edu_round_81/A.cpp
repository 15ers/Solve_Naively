#include <bits/stdc++.h>

using namespace std;

int exp(int s){
	int ret=1;
	while(s--)	ret *= 10;
	return ret;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int s=n/2-1;
		for(int i=s;i>=0;i--){
			if(n%2 && i==s)	printf("7");
			else	printf("1");
		}
		printf("\n");
	}
	return 0;
}