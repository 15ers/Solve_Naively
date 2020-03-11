#include <bits/stdc++.h>

using namespace std;

int n,p[20001],dist[20001];

int find(int n){
	if(p[n]<0)	return n;
	int tmp = find(p[n]);
	dist[n] += dist[p[n]];
	p[n] = tmp;
	return p[n];
}
void merge(int a, int b){
	dist[a] = abs(a-b)%1000;
	p[a] = b;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(p,-1,sizeof(p));
		memset(dist,0,sizeof(dist));
		scanf("%d",&n);
		char q;
		while(scanf(" %c",&q),q!='O'){
			if(q=='E'){
				int a;
				scanf("%d",&a);
				find(a);
				printf("%d\n",dist[a]);
			}
			else{
				int a,b;
				scanf("%d %d",&a,&b);
				merge(a,b);
			}
			getchar();
		}
	}

	return 0;
}
