#include <bits/stdc++.h>

using namespace std;

int n,s,cnt;
int arr[20] = {0};

void dfs(int idx, int ps){
	if(idx==n){
		if(ps==s)	cnt++;
		return;
	}
	dfs(idx+1,ps+arr[idx]);
	dfs(idx+1,ps);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> s;
	for(int i=0;i<n;i++)	cin >> arr[i];
	cnt = s ? 0 : -1;
	dfs(0,0);
	cout << cnt << endl;
	
	return 0;
}