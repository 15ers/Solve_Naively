
#include <bits/stdc++.h>

using namespace std;

int p[300001];
bool f[300001];

int find(int n){
	if(p[n]<0)	return n;
	return p[n] = find(p[n]);
}
void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b)	return;
	p[a] = b;
}

int main(){
	int n,l;
	memset(p,-1,sizeof(p));
	scanf("%d %d",&n,&l);
	for(int i=0;i<n;i++){
		int a,b;
		bool flag=true;
		scanf("%d %d",&a,&b);
		if(!f[a]){
			f[a] = true;
			merge(a,b);
		}
		else if(!f[b]){
			f[b] = true;
			merge(b,a);
		}
		else if(!f[find(a)]){
			f[find(a)] = true;
			merge(find(a),find(b));
		}
		else if(!f[find(b)]){
			f[find(b)] = true;
			merge(find(b),find(a));
		}
		else	flag = false;
		if(flag)	printf("LADICA\n");
		else	printf("SMECE\n");
	}	

	return 0;
}
