#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

int main(){
	int m[101][10];
	for(int i=1;i<10;i++)	m[1][i] = 1;
	int n;
	cin >> n;
	for(int i=2;i<=n;i++){
		for(int j=0;j<10;j++){
			if(j==0)	m[i][j] = m[i-1][1];
			else if(j==9)	m[i][j] = m[i-1][8];
			else	m[i][j] = (m[i-1][j-1]+m[i-1][j+1])%MOD;
		}
	}
	int s = 0;
	for(int i=0;i<10;i++)	s = (s+m[n][i])%MOD;
	cout << s << endl;
	
	return 0;
}