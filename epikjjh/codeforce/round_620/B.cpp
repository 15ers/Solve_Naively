#include <bits/stdc++.h>

using namespace std;

bool ispalindrome(string s){
	int si = s.size();
	for(int i=0;i<si/2;i++)	if(s[i]!=s[si-i-1])	return false;
	return true;
}

int main(){
	int n,m,ret=0;
	cin >> n >> m;
	string rets,single="",front="",rear="";
	vector<string> v(n);
	vector<pair<int,int>> doubles;
	for(auto &p: v)	cin >> p;
	for(int i=0;i<n;i++){
		if(ispalindrome(v[i]))	single = v[i];
		for(int j=i+1;j<n;j++)	if(ispalindrome(v[i]+v[j]))	doubles.push_back({i,j});
	}
	ret += 2*doubles.size()*m;
	if(!single.empty())	ret += m;
	for(int i=0;i<doubles.size();i++){
		front += v[doubles[i].first];
		rear = v[doubles[i].second]+rear;
	}
	rets = front + single + rear;
	cout << ret << endl;
	cout << rets << endl;
	
	return 0;
}