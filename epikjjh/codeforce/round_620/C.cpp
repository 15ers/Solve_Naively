#include <bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n,m;
		cin >> n >> m;
		vector<int> xord(n);
		vector<pair<int,int>> temp(n);
		for(int i=0;i<n;i++)	cin >> xord[i] >> temp[i].first >> temp[i].second;
		int l=m,h=m,pre_x=0;
		bool flag = true;
		for(int i=0;i<n;i++){
			int cur_x = xord[i];
			int dist = cur_x-pre_x;
			l -= dist;
			h += dist;
			if(h<temp[i].first || temp[i].second<l){
				flag = false;
				break;
			}
			if(temp[i].second<=h){
				l = max(l,temp[i].first);
				h = temp[i].second;
			}
			if(l<=temp[i].first){
				l = temp[i].first;
				h = min(h,temp[i].second);
			}
			pre_x = cur_x;
		}
		if(flag)	cout << "YES" << endl;
		else	cout << "NO" << endl;
	}
	
	return 0;
}