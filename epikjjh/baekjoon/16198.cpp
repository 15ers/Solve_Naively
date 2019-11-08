#include <bits/stdc++.h>

using namespace std;

int ret=0;

void dfs(vector<int> &arr, int score){
	if(arr.size()==2){
		if(score>ret)	ret = score;
		return;
	}
	for(int i=1;i<arr.size()-1;i++){
		int tmp = arr[i], tmp_sc = arr[i-1]*arr[i+1];
		score += tmp_sc;
		arr.erase(arr.begin()+i);
		dfs(arr,score);
		arr.insert(arr.begin()+i,tmp);
		score -= tmp_sc;
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)	cin >> arr[i];
	dfs(arr,0);
	cout << ret << endl;
	
	return 0;
}