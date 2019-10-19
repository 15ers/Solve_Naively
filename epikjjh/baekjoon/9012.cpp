#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	string p;
	cin >> t;
	while(t--){
		stack<char> s;
		cin >> p;
		for(int i=0;i<p.size();i++){
			if(!s.empty()&&s.top()=='('&&p[i]==')')	s.pop();
			else	s.push(p[i]);
		}
		cout << (s.empty() ? "YES" : "NO") << endl;
	}
	
	return 0;
}