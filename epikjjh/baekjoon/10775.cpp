#include <bits/stdc++.h>

using namespace std;

int pa[100001];

int find(int n){
	if(pa[n]<0)	return n;
	pa[n] = find(pa[n]);
	return pa[n];
}
void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b)	return;
	pa[b] = a;
}

int main(){
	int g,p,ret=0;
	bool flag=false;
	memset(pa,-1,sizeof(pa));
	scanf("%d %d",&g,&p);
	for(int i=0;i<p;i++){
		int tmp;
		scanf("%d",&tmp);
		if(flag)	continue;
		int root = find(tmp);
		if(root){
			merge(root-1,root);
			ret++;
		}
		else	flag = true;
	}
	printf("%d\n",ret);
	return 0;
}