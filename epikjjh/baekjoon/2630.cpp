#include <iostream>
#include <cstdio>

using namespace std;

int paper[128][128] = {0};
int blue = 0;
int white = 0;

int check(int size, int sp_r, int sp_c){
	int sum = 0;
	
	for(int i=sp_r;i<sp_r+size;i++)
		for(int j=sp_c;j<sp_c+size;j++)
			sum += paper[i][j];
	return sum;
}
void divide(int size, int sp_r, int sp_c){
	int ret = check(size,sp_r,sp_c);
	if(ret==0)
		white++;
	else if(ret==size*size)
		blue++;
	else{
		divide(size/2,sp_r,sp_c);
		divide(size/2,sp_r,sp_c+size/2);
		divide(size/2,sp_r+size/2,sp_c);
		divide(size/2,sp_r+size/2,sp_c+size/2);
	}	
}
int main(){
	int size;
	cin >> size;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			scanf("%d", &paper[i][j]);
	divide(size,0,0);
	cout << white << endl;
	cout << blue << endl;
	return 0;
}