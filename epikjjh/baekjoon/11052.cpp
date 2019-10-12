#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	vector<int> m(n+1),ans(n+1);
	for(int i=1;i<=n;i++)	cin >> m[i];
	ans[1] = m[1];
	for(int i=2;i<=n;i++){
		ans[i] = m[i];
		for(int j=i/2;j<i;j++)	ans[i] = max(ans[j]+ans[i-j],ans[i]);
	}
	cout << ans[n] << endl;
	return 0;	
}