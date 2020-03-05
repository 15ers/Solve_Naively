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
	if(p[a]<p[b])	swap(a,b);
	p[b] = a;
}

int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	p.resize(n+1);
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		p[i] = -1*tmp;
	}
	for(int i=0;i<m;i++){
		int v,w;
		scanf("%d %d",&v,&w);
		merge(v,w);
	}
	set<int> s;
	for(int i=1;i<=n;i++)	if(find(i)>0)	s.insert(find(i));
	int ret=0;
	for(int x: s)	ret += abs(p[x]);
	if(ret>k)	cout << "Oh no" << endl;
	else	cout << ret << endl;

	return 0;
}