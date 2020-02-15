#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,t,k;
	cin >> n >> m >> t >> k;
	vector<pair<int,int>> v(t);
	for(auto &p: v)	cin >> p.first >> p.second;
	int ret=0,ret_x=0,ret_y=0;
	for(int i=0;i<t;i++){
		int s_x = v[i].first;
		if(s_x+k>n)	s_x = n-k;
		for(int j=0;j<t;j++){
			int s_y = v[j].second;
			if(s_y+k>m)	s_y = m-k;
			int cnt=0;
			for(auto &p: v)	if(s_x<=p.first&&p.first<=s_x+k && s_y<=p.second&&p.second<=s_y+k)	cnt++;
			if(cnt>ret){
				ret_x = s_x;
				ret_y = s_y;
				ret = cnt;
			}
		}
	}
	cout << ret_x << " " << ret_y+k << endl;
	cout << ret << endl;
	
	return 0;
}