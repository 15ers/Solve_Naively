#include <bits/stdc++.h>

using namespace std;

vector<int> p;

int find(int n){
	if(p[n]<0)	return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a,int b){
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
	p.resize(n+1,-1);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int tmp;
			scanf("%d",&tmp);
			if(tmp)	merge(i+1,j+1);
		}
	}
	set<int> s;
	for(int i=0;i<m;i++){
		int tmp;
		scanf("%d",&tmp);
		s.insert(find(tmp));
	}
	if(s.size()==1)	printf("YES\n");
	else	printf("NO\n");
	
	return 0;
}