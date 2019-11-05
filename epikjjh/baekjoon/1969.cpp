#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,error=0;
	const char g[] = "ACGT";
	string ret = "";
	cin >> m >> n;
	vector<string> arr(m);
	for(int i=0;i<m;i++)	cin >> arr[i];
	for(int i=0;i<n;i++){
		int gene[4] = {0};
		for(int j=0;j<m;j++){
			if(arr[j][i]=='A')	gene[0]++;
			else if(arr[j][i]=='C')	gene[1]++;
			else if(arr[j][i]=='G')	gene[2]++;
			else	gene[3]++;
		}
		int max_num=0,max_idx=0;
		for(int k=0;k<4;k++){
			if(max_num<gene[k]){
				max_num = gene[k];
				max_idx = k;
			}
		}
		ret += g[max_idx];
		error += m-max_num;
	}
	cout << ret << endl;
	cout << error << endl;
	
	return 0;
}