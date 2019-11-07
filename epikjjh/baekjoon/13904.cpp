#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first)	return a.second<b.second;
	else	return a.first>b.first;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,d,w,ret=0;
	int schedule[1001] = {0};
	cin >> n;
	vector<pair<int,int> > table(n);
	for(int i=0;i<n;i++){
		cin >> d >> w;
		table[i] = make_pair(w,d);
	}
	sort(table.begin(),table.end(),cmp);
	for(int i=0;i<n;i++){
		int due = table[i].second, worth = table[i].first;
		for(int j=due;j>=1;j--){
			if(!schedule[j]){
				schedule[j] = worth;
				break;
			}
		}
	}
	for(int i=0;i<1001;i++)	ret += schedule[i];
	cout << ret << endl;
	
	return 0;
}