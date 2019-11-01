#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int tar;
	bool flag=false;
	cin >> tar;
	for(int i=1;i<=1000000;i++){
		int n=i,tmp=i;
		while(tmp>0){
			n += tmp%10;
			tmp /= 10;
		}
		if(tar==n){
			cout << i << endl;
			flag = true;
			break;
		}
	}
	if(!flag)	cout << 0 << endl;
	
	return 0;
}