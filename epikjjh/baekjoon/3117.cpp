#include <bits/stdc++.h>
#define MAX 100000
#define MAX_I 30

using namespace std;

int main(){
	int n,m,k,table[MAX+1][MAX_I];
	memset(table,0,sizeof(table));
	scanf("%d %d %d",&n,&k,&m);
	vector<int> arr(n+1);
	for(int i=1;i<=n;i++)	scanf("%d",&arr[i]);
	for(int i=1;i<=k;i++)	scanf("%d",&table[i][0]);
	for(int j=1;j<MAX_I;j++){
		for(int i=1;i<=k;i++)	table[i][j] = table[table[i][j-1]][j-1];
	}
	for(int i=1;i<=n;i++){
		int x=arr[i],t=m-1;
		for(int j=MAX_I-1;j>=0;j--){
			if(t>=(1<<j)){
				t -= (1<<j);
				x = table[x][j];
			}
		}
		printf("%d ",x);
	}
	printf("\n");
	
	return 0;
}