#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,open=0,close=0,score=0,ret=0;
	bool flag=false;
	string s;
	cin >> n >> s;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			open++;
			score++;
		}
		else{
			close++;
			score--;
		}
		if(score<0)	flag = true;
		if(flag){
			if(!score)	flag = false;
			ret++;
		}
	}
	if(open!=close)	cout << -1 << endl;
	else	cout << ret << endl;

	return 0;
}
