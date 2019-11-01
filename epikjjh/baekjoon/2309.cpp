#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int arr[9]={0};
	vector<int> ans;
	bool flag=false;
	for(int i=0;i<9;i++)	cin >> arr[i];
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			int sum = 0;
			for(int k=0;k<9;k++)	if(k!=i && k!=j)	sum += arr[k];
			if(sum==100){
				flag = true;
				for(int k=0;k<9;k++)	if(k!=i && k!=j)	ans.push_back(arr[k]);
				sort(ans.begin(),ans.end());
				for(int k=0;k<7;k++)	cout << ans[k] << endl;
				break;
			}
		}
		if(flag)	break;
	}
	return 0;
}