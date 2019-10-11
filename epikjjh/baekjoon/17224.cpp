#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n,l,k;
	int score[100];
	
	cin >> n >> l >> k;
	for(int i=0;i<n;i++){
		int a,b,s;
		cin >> a >> b;
		if(a<=l)
			s = (b<=l) ? 140 : 100;
		else
			s = 0;
		score[i] = s;
	}
	sort(score,score+n);
	int ans = 0;
	for(int i=n-1;i>n-k-1;i--){
		ans += score[i];
	}
	cout << ans << endl;
}