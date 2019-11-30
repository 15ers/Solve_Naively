#include <bits/stdc++.h>

using namespace std;
const int SIZE = 131072*2;

struct segTree{
	int size,leaf;
	long long tree[SIZE];
	segTree(int n): size(n){
		leaf = 1;
		while(leaf<size)	leaf *= 2;
		memset(tree,0,sizeof(tree));
	}
	void build_node(){
		for(int i=leaf-1;i>0;i--)	tree[i] = tree[i*2]+tree[i*2+1];
	}
	void update(int index, int value){
		index += leaf;
		long long diff = value - tree[index];
		while(index>0){
			tree[index] += diff;
			index /= 2;
		}
	}
	long long sum(int l, int r){
		return sum(1,l,r,0,leaf-1);
	}
	long long sum(int node, int l, int r, int n_l, int n_r){
		if(l<=n_l && n_r<=r)	return tree[node];
		if(r<n_l || n_r<l)	return 0;
		int mid = (n_l+n_r)/2;
		return sum(node*2,l,r,n_l,mid)+sum(node*2+1,l,r,mid+1,n_r);
	}
};

int main(){
	int n,q,a,b,x,y;
	scanf("%d %d", &n, &q);
	segTree st(n);
	for(int i=0;i<n;i++)	scanf("%lld",st.tree+st.leaf+i);
	st.build_node();
	while(q--){
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if(x>y)	swap(x,y);
		printf("%lld\n", st.sum(x-1,y-1));
		st.update(a-1,b);
	}
	
	return 0;
}