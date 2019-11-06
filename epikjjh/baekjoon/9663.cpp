#include <bits/stdc++.h>

using namespace std;

int cnt=0,n;
int arr[15] = {0};

void backtrack(int idx){
	if(idx==n)	cnt++;
	else{
		for(int i=0;i<n;i++){
			arr[idx] = i;
			bool flag = true;
			for(int j=0;j<idx;j++){
				if(arr[idx]==arr[j] || (idx-j)==abs(arr[idx]-arr[j])){
					flag = false;
					break;
				}
			}
			if(flag)	backtrack(idx+1);
		}
	}
	
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);	
	cin >> n;
	backtrack(0);
	cout << cnt << endl;
	
	return 0;
}