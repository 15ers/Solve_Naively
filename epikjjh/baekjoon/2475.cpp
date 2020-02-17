#include <bits/stdc++.h>

using namespace std;

int main(){
	int ret=0;
	for(int i=0;i<5;i++){
		int tmp;
		cin >> tmp;
		ret += tmp*tmp;
	}
	cout << ret%10 << endl;
	
	return 0;
}