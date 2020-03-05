#include <bits/stdc++.h>

using namespace std;

vector<int> p;

int find(int n){
	if(p[n]<0)	return n;
	p[n] = find(p[n]);
	return p[n];
}
void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b)	return;
	if(p[a]>p[b])	swap(a,b);
	p[a] += p[b];
	p[b] = a;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	p.resize(n+1);
	fill(p.begin(),p.end(),-1);
	while(m--){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(!a)	merge(b,c);
		else{
			if(find(b)==find(c))	printf("YES\n");
			else	printf("NO\n");
		}
	}
	
	return 0;
}