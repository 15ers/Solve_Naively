#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,k,ret=0;
	int order[100]={0};
	vector<int> tab;
	cin >> n >> k;
	for(int i=0;i<k;i++)	cin >> order[i];
	for(int i=0;i<k;i++){
		bool isin = false;
		for(int j=0;j<tab.size();j++){
			if(order[i]==tab[j]){
				isin = true;
				break;
			}
		}
		if(isin)	continue;
		if(tab.size()<n){
			tab.push_back(order[i]);
			continue;	
		}
		int farthest=-1,tab_idx=-1;
		bool flag=true;
		for(int l=0;l<n;l++){
			int loc_idx=-1;
			for(int j=i+1;j<k;j++){
				if(tab[l]==order[j]){
					loc_idx = j;
					break;
				}
			}
			if(loc_idx==-1){
				tab[l] = order[i];
				flag = false;
				ret++;
				break;
			}
			if(farthest<loc_idx){
				farthest = loc_idx;
				tab_idx = l;
			}
		}
		if(flag){
			tab[tab_idx] = order[i];
			ret++;	
		}
	}
	cout << ret << endl;
	
	return 0;
}