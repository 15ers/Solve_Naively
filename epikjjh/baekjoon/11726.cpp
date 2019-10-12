#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	vector<int> m(1001);
	m[0]=0,m[1]=1,m[2]=2;
	int n;
	cin >> n;
	for(int i=3;i<=n;i++)	m[i] = (m[i-1]+m[i-2])%10007;
	cout << m[n] << endl;
	
	return 0;
}