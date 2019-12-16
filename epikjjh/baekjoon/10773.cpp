#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	vector<int> stack;
	int n,t,ret=0;
	
	cin >> n;
	while(n--){
		cin >> t;
		if(t)	stack.push_back(t);
		else	stack.pop_back();
	}
	for(int i=0;i<stack.size();i++)	ret += stack[i];
	cout << ret << endl;
	
	return 0;
}