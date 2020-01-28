#include <bits/stdc++.h>

using namespace std;

int arr[5][5];

int check(){
	int ret=0;
	for(int i=0;i<5;i++){
		bool flag=true;
		for(int j=0;j<5;j++){
			if(arr[i][j]!=0){
				flag=false;
				break;
			}
		}
		if(flag)	ret++;
		flag=true;
		for(int j=0;j<5;j++){
			if(arr[j][i]!=0){
				flag=false;
				break;
			}
		}
		if(flag)	ret++;
	}
	bool flag=true;
	for(int i=0;i<5;i++){
		if(arr[i][i]!=0){
			flag=false;
			break;
		}
	}
	if(flag)	ret++;
	flag=true;
	for(int i=0;i<5;i++){
		if(arr[i][4-i]!=0){
			flag=false;
			break;
		}
	}
	if(flag)	ret++;
	return ret;
}

int main(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)	cin >> arr[i][j];
	}
	int ret=25;
	for(int t=0;t<25;t++){
		int tar;
		cin >> tar;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(arr[i][j]==tar){
					arr[i][j] = 0;
					break;
				}
			}
		}
		if(check()>=3)	ret=min(ret,t+1);
	}
	cout << ret << endl;
	
	return 0;
}