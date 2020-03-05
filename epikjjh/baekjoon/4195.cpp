#include <bits/stdc++.h>

using namespace std;

int p[200001];

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
int find_ind(string key, unordered_map<string,int> &arr){
	int ret;
	if(arr.find(key)==arr.end())	ret = arr[key] = arr.size()+1;
	else	ret = arr[key];
	return ret;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(p,-1,sizeof(p));
		unordered_map<string,int> arr;
		int f;
		cin >> f;
		for(int i=0;i<f;i++){
			string a,b;
			int ai,bi;
			cin >> a >> b;
			ai = find_ind(a,arr);
			bi = find_ind(b,arr);
			if(find(ai)!=find(bi))	merge(ai,bi);
			cout << abs(p[find(ai)]) << endl;
		}
	}

	return 0;
}