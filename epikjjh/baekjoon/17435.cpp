#include <bits/stdc++.h>
#define MAX 200000
#define MAX_I 19

using namespace std;


int main(){
	int m,table[MAX+1][MAX_I],q;
	cin >> m;
	for(int i=1;i<=m;i++)	scanf("%d",&table[i][0]);
	for(int j=1;j<MAX_I;j++){
		for(int i=1;i<=m;i++)	table[i][j] = table[table[i][j-1]][j-1];
	}
	cin >> q;
	while(q--){
		int n,x;
		scanf("%d %d",&n,&x);
		for(int i=MAX_I-1;i>=0;i--){
			if(n>=(1<<i)){
				n -= (1<<i);
				x = table[x][i];
			}
		}
		printf("%d\n",x);
	}
	return 0;
}