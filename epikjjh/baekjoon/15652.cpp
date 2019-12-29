#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> v;

void pperm(int cnt, int cur){
	if(cnt==m){
		for(int i=0;i<v.size();i++)	cout << v[i] << " ";
		cout << endl;
		return;
	}
	for(int i=cur;i<=n;i++)
		v.push_back(i);
		pperm(cnt+1,i);
		v.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	pperm(0,1);
	
	return 0;
}