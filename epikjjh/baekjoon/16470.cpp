#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cout.precision(6);
	map<string, int> m;
	string t;
	int s = 0;
	while(cin >> t){
		m[t]++;
		s++;
	}
	double tmp,sum=0;
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
		tmp = 1.0*(it->second)/s;
		sum += tmp*tmp;
	}
	cout << 1-sum << endl;
}