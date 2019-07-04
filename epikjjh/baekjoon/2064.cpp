#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;
typedef unsigned int uint;

void print_ans(uint target);

int main(){
	uint arr[1000]={0,};
	int n;
	
	cin >> n;
	cin.ignore();
	for(int i=0;i<n;i++){
		for(int j=3;j>=0;j--){
			uint ip;
			
			cin >> ip;
			arr[i] |= (ip << (j*8));
			getchar();
		}
	}
	uint bit = (1 << 31), mask=0, network;
	bool loop = true;
	
	while(bit&&loop){
		for(int i=1;i<n;i++){
			if((bit&arr[0]) == (bit&arr[i]));
			else{
				loop = false;
				break;
			}
		}
		if(loop){
			mask |= bit;
			bit = (bit >> 1);
		}
	}
	network = mask & arr[0];
	print_ans(network);
	print_ans(mask);
	
	return 0;
}
void print_ans(uint target){
	uint std = 255;
	
	for(int i=3;i>=0;i--){
		cout << (255 & (target>>(i*8)));
		if(i)
			cout << ".";
		else
			cout << endl;
	}
}