#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int n = s.size();
	deque<int> left,right;
	int l=987654321,r=0;
	for(int i=0;i<n;i++)	if(s[i]=='(')	left.push_back(i+1);
	for(int i=n-1;i>=0;i--)	if(s[i]==')')	right.push_back(i+1);
	vector<int> ret;
	if(!left.empty())	l = left.front();
	if(!right.empty())	r = right.front();
	while(l<r){
		ret.push_back(l);
		ret.push_back(r);
		left.pop_front();
		right.pop_front();
		if(left.empty() || right.empty())	break;
		l = left.front();
		r = right.front();
	}
	if(ret.empty())	cout << 0 << endl;
	else{
		sort(ret.begin(),ret.end());
		cout << 1 << endl;
		cout << ret.size() << endl;
		for(auto &p: ret)	cout << p << " ";
		cout << endl;
	}
	
	return 0;
}