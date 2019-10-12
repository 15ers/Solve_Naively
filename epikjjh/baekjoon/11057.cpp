#include <bits/stdc++.h>
#define MOD 10007

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int arr[1001][10];
	int n;
	cin >> n;
	for(int i=0;i<10;i++)	arr[1][i] = 1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<10;j++){
			if(!j)	arr[i][j] = arr[i-1][j];
			else	arr[i][j] = (arr[i-1][j]+arr[i][j-1])%MOD;
		}
	}
	int s=0;
	for(int i=0;i<10;i++)	s = (s+arr[n][i])%MOD;
	cout << s << endl;
	
	return 0;
}