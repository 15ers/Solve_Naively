#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	long long int n,p,w,d;
	cin >> n >> p >> w >> d;
	bool flag = false;
	for(int i=0;i<w;i++){
		if(p>=d*i && (p-d*i)%w==0){
			if(i+(p-d*i)/w<=n){
				flag = true;
				cout << (p-d*i)/w << " " << i << " " << n-i-(p-d*i)/w << endl;
				break;
			}
		}
	}
	if(!flag)	cout << -1 << endl;
	
	return 0;
}