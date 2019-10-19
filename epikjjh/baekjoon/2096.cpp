#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,dp_min[3]={0},dp_max[3]={0},cur_min[3]={0},cur_max[3]={0};
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin >> cur_max[j];
			cur_min[j] = cur_max[j];
			cur_max[j] += max(dp_max[1],(j==1)?max(dp_max[0],dp_max[2]):dp_max[j]);
			cur_min[j] += min(dp_min[1],(j==1)?min(dp_min[0],dp_min[2]):dp_min[j]);
		}
		for(int j=0;j<3;j++){
			dp_max[j]=cur_max[j];
			dp_min[j]=cur_min[j];
		}
	}
	sort(dp_max,dp_max+3);
	sort(dp_min,dp_min+3,greater<int>());
	cout << dp_max[2] << " " << dp_min[2] << endl;
	
	return 0;
}