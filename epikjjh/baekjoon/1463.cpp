#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	vector<int> m(1000001);
	m[0] = m[1] = 0, m[2] = m[3] = 1;
	int n;
	cin >> n;
	for(int i=4;i<=n;i++){
		m[i] = m[i-1] + 1;
		if(!(i%2)){
			m[i] = min(m[i],m[i/2]+1);
		}
		if(!(i%3))	m[i] = min(m[i],m[i/3]+1);
	}
	cout << m[n] << endl;
	return 0;
}