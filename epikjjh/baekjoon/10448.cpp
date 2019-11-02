#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int arr[46] = {0};
	for(int i=1;i<46;i++)	arr[i] = i*(i+1)/2;
	int t;
	cin >> t;
	while(t--){
		bool flag=false;
		int n;
		cin >> n;
		for(int i=1;i<46;i++){
			for(int j=1;j<46;j++){
				for(int k=1;j<46;k++){
					if(n==arr[i]+arr[j]+arr[k])	flag=true;
					if(n<=arr[i]+arr[j]+arr[k]) break;
				}
				if(flag || n<arr[i]+arr[j])	break;
			}
			if(flag || n<arr[i])	break;
		}
		int ret = flag ? 1 : 0;
		cout << ret << endl;
	}
	
	return 0;
}