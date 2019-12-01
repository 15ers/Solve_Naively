#include <bits/stdc++.h>

using namespace std;

const int SIZE = 131072*2;

struct maxTree{
	int size,leaf;
	int tree[SIZE];
	
	maxTree(int n): size(n){
		leaf = 1;
		while(leaf<size)	leaf *= 2;
		memset(tree,0,sizeof(tree));
	}
	
	void update(int index){
		int value = find(1,0,index,0,leaf-1)+1;
		index += leaf;
		tree[index] = value;
		index /= 2;
		while(index>0){
			tree[index] = max(tree[index*2],tree[index*2+1]);
			index /= 2;
		}
	}
	int find(int node, int l, int r, int n_l, int n_r){
		if(l<=n_l && n_r<=r)	return tree[node];
		if(r<n_l || n_r<l)	return 0;
		int mid = (n_l+n_r)/2;
		return max(find(node*2,l,r,n_l,mid),find(node*2+1,l,r,mid+1,n_r));
	}
};

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first)	return a.second>b.second;
	else	return a.first<b.first;
}
int main(){
	int n,v;
	scanf("%d", &n);
	maxTree mt(n);
	vector<pair<int,int> > arr(n);
	for(int i=0;i<n;i++){
		scanf("%d", &v);
		arr[i] = make_pair(v,i);
	}
	sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<n;i++)	mt.update(arr[i].second);
	
	printf("%d\n", n-mt.tree[1]);
	
	return 0;
}