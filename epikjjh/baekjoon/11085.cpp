#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

vector<int> pa;

bool cmp(pair<int,P> &a, pair<int,P> &b){
	return a.first>b.first;	
}

int find(int n){
	if(pa[n]<0)	return n;
	pa[n] = find(pa[n]);
	return pa[n];
}
void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b)	return;
	if(pa[a]>pa[b])	swap(a,b);
	pa[a] += pa[b];
	pa[b] = a;
}

int main(){
	int p,w,s,e;
	scanf("%d %d %d %d",&p,&w,&s,&e);
	vector<pair<int,P>> arr;
	pa.resize(p,-1);
	for(int i=0;i<w;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		arr.push_back({c,{a,b}});
	}
	sort(arr.begin(),arr.end(),cmp);
	for(auto p: arr){
		int a=p.second.first;
		int b=p.second.second;
		int c=p.first;
		merge(a,b);
		if(find(s)==find(e)){
			cout << c << endl;
			break;
		}
	}
	
	return 0;
}