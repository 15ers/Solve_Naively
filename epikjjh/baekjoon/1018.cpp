#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m;
	cin >> n >> m;
	string	arr[50];
	int ret = 987654321;
	for(int i=0;i<n;i++)	cin >> arr[i];
	for(int i=0;i<n-7;i++){
		for(int j=0;j<m-7;j++){
			int even=0,odd=0;
			for(int k=0;k<8;k++){
				for(int l=0;l<8;l++){
					if(arr[i+k][j+l]=='B'){
						if((k+l)%2==0)	even++;
						else	odd++;
					}
					else{
						if((k+l)%2==0)	odd++;
						else	even++;
					}
				}
			}
			ret = min(ret,min(even,odd));
		}
	}
	cout << ret << endl;
	
	return 0;
}