#include <bits/stdc++.h>

using namespace std;

int p[100001];

int find(int n){
	if(p[n]<0)	return n;
	return p[n] = find(p[n]);
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
	int n,m,q;
	memset(p,-1,sizeof(p));
	scanf("%d %d %d",&n,&m,&q);	
	vector<pair<int,int>> queryset(m+1);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		queryset[i] = {a,b};
	}	
	vector<int> order(q);
	vector<bool> check(m+1,false);
	for(int &t: order){
		scanf("%d",&t);
		check[t] = true;
	}
	for(int i=1;i<=m;i++)	if(!check[i])	merge(queryset[i].first,queryset[i].second);
	reverse(order.begin(),order.end());
	long long ret=0;
	for(int &t: order){
		int a = queryset[t].first;
		int b = queryset[t].second;
		if(find(a)!=find(b))	ret += 1LL*p[find(a)]*p[find(b)];
		merge(a,b);
	}
	printf("%lld\n",ret);
	
	return 0;
}
