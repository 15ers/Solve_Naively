#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans=0,cnt=0,max_d=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				if(i==0 || i==n-1){
					ans = 2*n;
					break;
				}
				cnt++;
				int d = max(i+1,n-i);
				max_d = max(d,max_d);
			}
		}
		if(ans)	cout << ans << endl;
		else{
			ans = max(n+cnt,2*max_d);
			cout << ans << endl;
		}
	}
	return 0;
}