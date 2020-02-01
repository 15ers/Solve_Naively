#include <bits/stdc++.h>

using namespace std;

int main(){
	int me=0,mi=0;
	for(int i=0;i<9;i++){
		int tmp;
		cin >> tmp;
		if(tmp>me){
			me = tmp;
			mi = i;
		}
	}
	cout << me << endl;
	cout << mi+1 << endl;
	
	return 0;
}