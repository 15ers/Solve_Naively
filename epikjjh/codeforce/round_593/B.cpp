#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	long long int s=1,ret;
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)	s *= 2%(1000000000+7);
	s--;
	ret = s;
	for(int i=1;i<n;i++)	ret = ret*s%(1000000000+7);
	cout << ret << endl;
	
	return 0;
}