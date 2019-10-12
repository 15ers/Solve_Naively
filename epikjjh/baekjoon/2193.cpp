#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	long long int m[91][2];
	m[1][1] = 1, m[1][0] = 0;
	for(int i=2;i<=n;i++){
		m[i][0] = m[i-1][0]+m[i-1][1];
		m[i][1] = m[i-1][0];
	}
	cout << m[n][0]+m[n][1] << endl;
	return 0;
}