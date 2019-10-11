#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	vector<int> m(n),e(n);
	for(int i=0;i<n;i++)	cin >> m[i];
	for(int i=0;i<n;i++)	cin >> e[i];
	sort(m.begin(),m.end());
	sort(e.begin(),e.end());
	bool flag = true;
	for(int i=0;i<(n+1)/2;i++){
		if(m[i]>=e[int(n/2)+i]){
			cout << "NO" << endl;
			flag = false;
			break;
		}
	}
	if(flag)	cout << "YES" << endl;
	return 0;
}