#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t,n,m,tmp;
	long long int result;
	cin >> t;
	while(t--){
		long long int n_odd=0,n_even=0,m_odd=0,m_even=0;
		cin >> n;
		while(n--){
			cin >> tmp;
			if(tmp%2==0)	n_even++;
			else	n_odd++;
		}
		cin >> m;
		while(m--){
			cin >> tmp;
			if(tmp%2==0)	m_even++;
			else	m_odd++;
		}
		result = n_even*m_even+n_odd*m_odd;
		cout << result << endl;
	}
	
	return 0;
}