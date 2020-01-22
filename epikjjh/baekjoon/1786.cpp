#include <bits/stdc++.h>

using namespace std;

int main(){
	string p,t;
	int n,m;
	vector<int> ret;
	
	getline(cin,p);
	getline(cin,t);
	n = p.size();
	m = t.size();
	vector<int> fail(m);
	for(int i=1,j=0;i<m;i++){
		while(j>0 && t[i]!=t[j])	j = fail[j-1];
		if(t[i]==t[j])	fail[i] = ++j;
	}
	for(int i=0,j=0;i<n;i++){
		while(j>0 && p[i]!=t[j])	j = fail[j-1];
		if(p[i]==t[j]){
			if(j==m-1){
				ret.push_back(i-m+2);
				j = fail[j];
			}
			else	j++;
		}
	}
	cout << ret.size() << endl;
	for(int i: ret)	cout << i << endl;
	
	return 0;
}