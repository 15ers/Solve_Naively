#include <bits/stdc++.h> 
#define MAX 1000000000
#define MIN 1

using namespace std;
const int SIZE = 1048576*2;

struct minTree{
	int size,leaf;
	int tree[SIZE];
	minTree(int n): size(n){
		leaf = 1;
		while(leaf<size)	leaf *= 2;
		memset(tree,0,sizeof(tree));
	}
	void build_node(){
		for(int i=leaf-1;i>0;i--)	tree[i] = min(tree[i*2],tree[i*2+1]);
	}
	int find(int l, int r){
		return find(1,l,r,0,leaf-1);
	}
	int find(int node, int l, int r, int n_l, int n_r){
		if(l<=n_l && n_r<=r)	return tree[node];
		if(r<n_l || n_r<l)	return MAX;
		int mid = (n_l+n_r)/2;
		return min(find(node*2,l,r,n_l,mid), find(node*2+1,l,r,mid+1,n_r));
	}
};
struct maxTree{
	int size,leaf;
	int tree[SIZE];
	maxTree(int n): size(n){
		leaf = 1;
		while(leaf<size)	leaf *= 2;
		memset(tree,0,sizeof(tree));
	}
	void build_node(){
		for(int i=leaf-1;i>0;i--)	tree[i] = max(tree[i*2],tree[i*2+1]);
	}
	int find(int l, int r){
		return find(1,l,r,0,leaf-1);
	}
	int find(int node, int l, int r, int n_l, int n_r){
		if(l<=n_l && n_r<=r)	return tree[node];
		if(r<n_l || n_r<l)	return MIN;
		int mid = (n_l+n_r)/2;
		return max(find(node*2,l,r,n_l,mid), find(node*2+1,l,r,mid+1,n_r));
	}
};

int main(){
	int n,m,num,a,b;
	scanf("%d %d",&n, &m);
	minTree mint(n);
	maxTree maxt(n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		mint.tree[mint.leaf+i] = maxt.tree[maxt.leaf+i] = num;
	}
	mint.build_node();
	maxt.build_node();
	for(int i=0;i<m;i++){
		scanf("%d %d", &a, &b);
		printf("%d %d\n", mint.find(a-1,b-1), maxt.find(a-1,b-1));
	}
	
	return 0;
}