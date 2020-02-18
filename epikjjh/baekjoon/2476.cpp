#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,ret=0;
	cin >> n;
	while(n--){
		int arr[7];
		memset(arr,0,sizeof(arr));
		for(int i=0;i<3;i++){
			int tmp;
			cin >> tmp;
			arr[tmp]++;
		}
		int cnt=0,cnt_e=0;
		for(int i=6;i>=1;i--){
			if(arr[i]>cnt){
				cnt = arr[i];
				cnt_e = i;
			}
		}
		if(cnt==3)	ret = max(ret,10000+cnt_e*1000);
		else if(cnt==2)	ret = max(ret,1000+cnt_e*100);
		else	ret = max(ret,cnt_e*100);
	}
	cout << ret << endl;
	
	return 0;
}