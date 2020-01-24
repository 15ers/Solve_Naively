#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,s,k;
		cin >> n >> s >> k;
		vector<int> fail(k);
		for(int i=0;i<k;i++)	cin >> fail[i];
		int u=s,d=s;
		while(1){
			bool flag_u=true,flag_d=true;
			if(u>n)	flag_u = false;
			if(d<1)	flag_d = false;
			for(int i=0;i<k;i++){
				if(fail[i]==u)	flag_u = false;
				if(fail[i]==d)	flag_d = false;
			}
			if(flag_u||flag_d)	break;
			u++;
			d--;
		}
		cout << min(abs(s-u),abs(s-d)) << endl;
	}
	
	return 0;
}