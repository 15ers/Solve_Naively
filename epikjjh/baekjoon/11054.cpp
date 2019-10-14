#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,ret=0;
	cin >> n;
	vector<int> arr(n),fd(n),bd(n);
	fd[0] = bd[n-1] = 1;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		for(int j=0;j<i;j++)	fd[i] = max(fd[i],(arr[i]>arr[j])*fd[j]+1);
	}
	for(int i=n-1;i>=0;i--)	for(int j=n-1;j>i;j--)	bd[i] = max(bd[i],(arr[i]>arr[j])*bd[j]+1);
	for(int i=0;i<n;i++)	ret = max(ret,fd[i]+bd[i]-1);
	cout << ret << endl;
	
	return 0;
}