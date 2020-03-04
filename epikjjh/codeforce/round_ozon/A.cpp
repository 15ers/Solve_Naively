#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n),b(n);
		for(auto &p: a)	cin >> p;
		for(auto &p: b)	cin >> p;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(auto &p: a)	cout << p << " ";
		cout << endl;
		for(auto &p: b)	cout << p << " ";
		cout << endl;
	}
	
	return 0;
}