#include <bits/stdc++.h>

using namespace std;

int main(){
	for(int i=0;i<3;i++){
		int s=0;
		for(int j=0;j<4;j++){
			int tmp;
			cin >> tmp;
			s += tmp;
		}
		switch(s){
			case 4:
				cout << 'E' << endl;
				break;
			case 3:
				cout << 'A' << endl;
				break;
			case 2:
				cout << 'B' << endl;
				break;
			case 1:
				cout << 'C' << endl;
				break;
			default: 
				cout << 'D' << endl;
		}
	}
	
	return 0;
}